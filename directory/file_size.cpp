#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
    for (const auto& i :fs::directory_iterator(".") ) {
        if (fs::is_regular_file(i)) {
            i.file_size();
        } else {
            continue;
        }
    }
}