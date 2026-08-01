#include <iostream>
#include <filesystem>
namespace fs  =  std::filesystem;

int main() {
    int count=0; // note: if i will not assign a number the int variable will not asign zero by it's default and therefore it willl use rancom bits
    for (const auto& i : fs::directory_iterator(".")) {
        std::cout << i<<std::endl;
        count++;

    }
    int total=0;
    std::cout << "###########################################################"<<std::endl;
    for (const auto& j: fs::recursive_directory_iterator(".")) {
        std::cout <<j <<std::endl;
        
        total++;
    }
    std::cout <<"the total number of files and folder ijn the only directoty are are: " <<count << std::endl;
    std::cout <<"the total number of all the files and nested folders in this directoty are are: " <<total<< std::endl;
    // note: this std::filesystem::recursive_directory_iterator 
    
    
}