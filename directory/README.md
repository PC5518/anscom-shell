# native C++ Is extremely fast for the shell and directory scanning
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

