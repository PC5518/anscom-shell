#include <iostream>
#include <filesystem>
namespace fs  =  std::filesystem;
int main() {
    for (const auto& i : fs::directory_iterator(".")) {
        std::cout << i<<std::endl;
    }
}