#include <iostream>
#include <filesystem>

int main() {
    for (const auto& i : std::filesystem::directory_iterator(".")) {
        std::cout << i<<std::endl;
    }
}