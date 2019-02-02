#include "./cli-textformatpp/src/textformatpp.h"
#include "../src/Integer.h"
#include <iostream>;

void message(bool condition, std::string msg) {
    if(condition) {
        std::cout << text::green("ACCEPT: ") << text::green(msg) << std::endl;
    } else {
        std::cout << text::red("DENIED: ") << text::red(msg) << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
