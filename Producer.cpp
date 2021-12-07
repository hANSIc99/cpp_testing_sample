#include <iostream>
#include <sstream>
#include "Generator.h"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Enter the number of elements as argument" << std::endl;
        return -1;
    }

    int range = 0;

    try
    {
        range = std::stoi(argv[1]);
    }
    catch (const std::invalid_argument&)
    {
        std::cerr << "Error: Cannot parse \"" << argv[1] << "\" ";
        return -1;
    }
    catch (const std::out_of_range&) {
        std::cerr << "Error: " << argv[1] << " is out of range";
        return -1;
    }
    
    if (range <= 0) {
        std::cerr << "Error: Zero or negative number provided: " << argv[1];
        return -1;
    }

    std::stringstream data;

    std::cout << Generator::generate(data, range).rdbuf();
}