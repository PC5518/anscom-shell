#include <iostream>
#include <filesystem>
#include <system_error>
namespace fs= std::filesystem;

int main() {
    int files =0, folders =0,denied_count=0; 
    std::error_code error_data;
    try {
        for (const auto& i : fs::recursive_directory_iterator("/root")) {
            
    }
    }

        // if (ec) evaluates to true: This means an error did happen (the integer value is non-zero).if (!ec) evaluates to true: This means success (the integer value is 0).
        //  Yes, std::error_code evaluates to true when it stores an error value, meaning ec.value() != 0
    std::cout <<"files: " << files<<std::endl;
    std::cout <<"folder: " <<folders <<std::endl;
    std::cout <<"error: " << denied_count<<std::endl;
    return 0;


}
// What makes it smart, specifically: it separates two questions that are easy to accidentally conflate — "what is the answer" and "was I even able to get an answer." A lot of buggy code (in any language, not just C++) fails exactly because it doesn't make that separation, and ends up trusting a "false" that actually meant "couldn't check" rather than "actually false." You'd get silently wrong data instead of an honest "I don't know." This error_code pattern forces that distinction to be explicit, every single time you call it.
