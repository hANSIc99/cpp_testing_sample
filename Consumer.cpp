#include <iostream>
#include <sstream>

int main(int argc, char** argv){

#ifndef NDEBUG
    freopen("build/data.txt", "r", stdin);
#endif

    std::cout << "Consumer: ";
    std::string lineInput;
    while (std::cin >> lineInput){

        std::cout << lineInput;
    }
    std::cout << std::endl;
}