
#include <iostream>
#include <filesystem>
#include <system_error>
namespace fs= std::filesystem;

int main() {
    int files =0 ,folders=0, locked_folders =0;
    std::error_code error_data;
    for (const auto& i : fs::directory_iterator("/root")) {
    try {
        if (fs::is_directory(i)) {
            folders++;
        } else {
            files++;
        }
    } catch (const fs::filesystem_error& e) {
        locked_folders++;
        std::cout << "Caught: " << e.what() << std::endl; // ok  it means to basically reveal or expose the actual error at runtime wihout intersuppitng the run and display on the console
    }
}
    std::cout << locked_folders<<std::endl;
}
// What makes it smart, specifically: it separates two questions that are easy to accidentally conflate — "what is the answer" and "was I even able to get an answer." A lot of buggy code (in any language, not just C++) fails exactly because it doesn't make that separation, and ends up trusting a "false" that actually meant "couldn't check" rather than "actually false." You'd get silently wrong data instead of an honest "I don't know." This error_code pattern forces that distinction to be explicit, every single time you call it.
// issue witht this code:  when an exception is thrown anywhere inside a try block, C++ immediately abandons everything else inside that try — including any loop it was running — and jumps straight to the matching catch. It doesn't "skip this one folder and continue the loop." It destroys the entire loop's progress on the spot. So yes: one denied folder, out of potentially thousands, kills the whole scan. That's a real, serious weakness for a file scanner meant to walk huge, messy real-world directories
