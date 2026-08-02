#include <iostream>
#include <filesystem>
#include <system_error>
namespace fs= std::filesystem;

int main() {
    std::error_code error_data;
    int files=0;
    int folder=0;
    int denied_count= 0;
    for (const auto& i: fs::recursive_directory_iterator("/root", fs::directory_options::skip_permission_denied)) {
        std::cout << i<<std::endl;
        bool isDir= fs::is_directory(i, error_data); // yes, this one line is genuinely doing two things at once — that's a correct and important observation.
        if (error_data) {
            denied_count++;
            error_data.clear();
        } else if (isDir) { 
            folder++;
        } else {
            files++;
        }
        // if (ec) evaluates to true: This means an error did happen (the integer value is non-zero).if (!ec) evaluates to true: This means success (the integer value is 0).
    }  //  Yes, std::error_code evaluates to true when it stores an error value, meaning ec.value() != 0
        std::cout <<"files: " << files<<std::endl;
        std::cout <<"folder: " <<folder <<std::endl;
        std::cout <<"error: " << denied_count<<std::endl;


}
// What makes it smart, specifically: it separates two questions that are easy to accidentally conflate — "what is the answer" and "was I even able to get an answer." A lot of buggy code (in any language, not just C++) fails exactly because it doesn't make that separation, and ends up trusting a "false" that actually meant "couldn't check" rather than "actually false." You'd get silently wrong data instead of an honest "I don't know." This error_code pattern forces that distinction to be explicit, every single time you call it.