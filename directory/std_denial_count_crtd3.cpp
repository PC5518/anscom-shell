#include <iostream>
#include <filesystem>
#include <system_error>
namespace fs=std::filesystem;
int main() {
    int files=0;
    int folders =0;
    int denied_count=0;
    std::error_code error_data;
    for (const auto& i : fs::recursive_directory_iterator("/root", fs::directory_options::skip_permission_denied)) {
        bool isdir = fs::is_directory(i,error_data);  // note  in this  fs::directory_options::skip_permission_denied) the loop body is also ecxecuted the skip permission denied only make it silent and makes the code throw no error.
        // why this code doesn't work:  The option silences the error: By using fs::directory_options::skip_permission_denied, you tell the iterator to completely skip permission-denied items in the background.
        if (error_data) {
            denied_count++;
            folders++;  // However, a std::filesystem::recursive_directory_iterator can encounter errors or throw exceptions on things that are not folders (for example, broken symlinks, locked system files, or unreadable files).
            error_data.clear();
        } else if  (isdir) {
            folders++;
        } else {
            files++;
        }
    }
    std::cout << "directory details: " <<std::endl;
    std::cout << denied_count <<std::endl;
}//std::filesystem::directory_options::skip_permission_denied does not skip your loop's code. It tells the directory iterator to silently ignore access-denied folders and move straight to the next readable file or folder without throwing an error. Your loop body runs normally for every valid item.