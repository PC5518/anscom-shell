#include <iostream>
#include <filesystem>
namespace fs  =  std::filesystem;

int main() {
    int files=0;
    int folders=0;
    
    for (const auto& i : fs::recursive_directory_iterator("/root", fs::directory_options::skip_permission_denied) ) {
        if (fs::is_regular_file(i)) {
            files ++;
        } else {
            folders++;
        }
    }
    std::cout <<"files: " <<files<<std::endl;
    std::cout << "folders: " <<folders <<std::endl;
    

}
