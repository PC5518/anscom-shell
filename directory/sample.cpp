#include <iostream>
#include <filesystem>
namespace fs= std::filesystem;

int main() {
    int denial_count =0;
    std::error_code env ;
    std::cout<< env<<std::endl ;
    // cheking the type
    // for (const auto& i: fs::recursive_directory_iterator(".",  fs::directory_options::skip_permission_denied)) {
    //     if (fs::is_directory())
    // }
}
