
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