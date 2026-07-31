#include <iostream>
#include <filesystem>
namespace fs  =  std::filesystem;
int main() {
    int count=0; // note: if i will not assign a number the int variable will not asign zero by it's default and therefore it willl use rancom bits
    for (const auto& i : fs::directory_iterator(".")) {
        std::cout << i<<std::endl;
        count++;

    }
    
    std::cout <<"the total number of files are: " <<count << std::endl;
}