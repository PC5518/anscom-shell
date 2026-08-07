#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
    int denied=0;
    auto options= fs::directory_options::skip_permission_denied;
    for (const auto& i :fs::recursive_directory_iterator(".", options) ) {
        if (fs::is_regular_file(i)) {
            std::cout << i<<": "<<fs::file_size(i) <<std::endl;
        } else {
            continue;
        }
    }
    
}