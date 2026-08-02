#include <iostream>
#include <filesystem>
namespace fs =std::filesystem;
int main() {
    int folders=0;
    for (const auto& i : fs::recursive_directory_iterator(".")) {
        if (fs::is_directory(i)) {  // basically it returns true if the following component is a directory
            folders++;
        }
    }
    std::cout<< folders <<std::endl;
}//  output: 1 