#include <iostream>
#include <string>
int main() {
    while (true) {
        std::cout<< "anscom: $   " ;
        std::string input;
        std::getline(std::cin, input);
        if (input == "about") {
            std::cout <<"this is a pre maded version of anscom terminal shell" << std::endl;
        }
        else if (input == "exit") {
            break;
        }
        else {
            std::cout <<"the command " << input << " not found" << std::endl;
        }
    }
}
// SAMPLE COMMIT