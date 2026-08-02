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
    std::cout <<"output:  Abort" <<std::endl;
    // this fs::directory optuions is a gatway to take steps at a particular instance and this skip permisision denied instead of throwing, the iterator just treats /root as if it were empty — it silently moves on without ever giving you any of its contents

}
