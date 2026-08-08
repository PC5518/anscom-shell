# native C++ Is extremely fast for the shell and directory scanning
final video demo for the architecture structure:  https://youtu.be/G1dR3heCXJQ
<img width="1920" height="1080" alt="Screenshot From 2026-08-02 16-42-25" src="https://github.com/user-attachments/assets/f11245bc-c41c-4aea-9c44-6cfb0e536e62" />


# issue with the std::filesystem:: when it comes to the secured linux folders like /root and other. it's showing permission denied.
<img width="1920" height="1080" alt="Screenshot From 2026-08-02 16-30-21" src="https://github.com/user-attachments/assets/4974e685-85d2-4011-8f65-b896b1a96fd8" />


<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/c5d69002-3eea-4c88-a01f-d630e15f8f7c" />
this is the exact error to be handled. 


## this is not even a cath error. 
<img width="1320" height="832" alt="image" src="https://github.com/user-attachments/assets/80d6a563-a567-4d5b-8df9-faa715563aec" />

##  this is the exact error we are seeing. this is the exact error to be catched: terminate called after throwing an instance of 'std::filesystem::__cxx11::filesystem_error'

<img width="842" height="571" alt="image" src="https://github.com/user-attachments/assets/c5bbcaba-f090-4f4f-9684-602cd6ba8d83" />


## we can use this to go through the for deep level scanner without hurdles. this is for linux  distro ubuntu or fedora or even mac also.
// now the problem is that how will we deal with windows 11 or 10 ? it's mostly dependent on the GUI (Graphical User Interface).
<img width="990" height="608" alt="image" src="https://github.com/user-attachments/assets/ae17671e-3eb8-422e-8b5a-b01ef030938e" />


## weak point about the **catch and try** approach:
when an exception is thrown anywhere inside a try block, C++ immediately abandons everything else inside that try — including any loop it was running — and jumps straight to the matching catch. It doesn't "skip this one folder and continue the loop." It destroys the entire loop's progress on the spot. So yes: one denied folder, out of potentially thousands, kills the whole scan. That's a real, serious weakness for a file scanner meant to walk huge, messy real-world directories
// let's the follow the approach to make the try and catch in the for loop. 

now the for if loop works well with system_error  technique but still there is a file junction or some other kinnd of error 


## The biggst issues with the below code is with MS Windows:
'''

#include <iostream>
#include <filesystem>
#include <system_error>
namespace fs=std::filesystem;
int main() {
    int files=0;
    int folders =0;
    int denied_count=0;
    std::error_code error_data;
    for (const auto& i : fs::recursive_directory_iterator(".", fs::directory_options::skip_permission_denied)) {
        std::cout << i<<" " ;
        bool isdir = fs::is_directory(i,error_data);  // note  in this  fs::directory_options::skip_permission_denied) the loop body is also ecxecuted the skip permission denied only make it silent and makes the code throw no error.
        // why this code doesn't work:  The option silences the error: By using fs::directory_options::skip_permission_denied, you tell the iterator to completely skip permission-denied items in the background.
        if (error_data) {
            denied_count++; // However, a std::filesystem::recursive_directory_iterator can encounter errors or throw exceptions on things that are not folders (for example, broken symlinks, locked system files, or unreadable files).
            error_data.clear();
            std::cout <<"   ---> denied entry: file cannot be opened" <<std::endl;
        } else if  (isdir) {
            folders++; 
            std::cout<<"  ---->folder detected" <<std::endl;
        } else {
            files++;
            std::cout << " ----->files detected"<<std::endl;
        } // use sudo 
    }
    std::cout << "directory details: " <<std::endl;
    std::cout <<"total denied count: " << denied_count <<std::endl;
    std::cout <<"total files: " << files  <<std::endl;
    std::cout << "total folders: " << folders<<std::endl;
    std::cout << "total files, folders and denied files combined: " << folders+files + denied_count<<std::endl;
#if defined(_WIN32) 
    std::cout <<"Suggestion: for the most accurate results on MS Windows run in the administrator mode or with sudo. you might sudo with wsl for the best results. wsl: sudo ./sampleexefile" <<std::endl;
#elif defined(__linux__) 
    std::cout << "Suggestion: For the most accurate results on Linux machine run use with sudo.  Bash: sudo ./sampleexefile"<<std::endl;
#elif defined(__APPLE__)
    std::cout << "Suggestion: For the most accurate results on appple's mac machine run use with sudo.  Bash: sudo ./sampleexefile"<<std::endl;

#else
    std::cout <<"run the shell with admin access for best results" <<std::endl;
#endif 

    return 0;
}//std::filesystem::directory_options::skip_permission_denied does not skip your loop's code. It tells the directory iterator to silently ignore access-denied folders and move straight to the next readable file or folder without throwing an error. Your loop body runs normally for every valid item.
'''
Point 1:

skip_permission_denied handles only one specific category of errors — permission denied. In a filesystem, there can be many other categories of errors (like the current “Invalid argument,” reparse points, broken symlinks, disk I/O failures). No single flag can “handle everything” — each category requires its own handling. This is a genuine, permanent, real-world truth — professional scanning code (like your own anscom.c) maintains an entire layer of robust error handling for this reason, not just a single flag.

Point 2:

“Putting a try block inside the for loop didn’t solve the problem.”

Placing a try block inside the for loop only protects the loop body (the part you write yourself). But here, the issue is occurring in the loop’s internal “fetch next item” step (the increment), which a range-based for loop performs automatically and outside your control. That’s why putting a try block inside the body doesn’t even touch it — the crash is happening in the loop’s mechanism, not in your written code.
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/18efa2b0-2a1c-4aca-b0fb-ad1c69c44a61" />
