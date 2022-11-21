// Implement UNIX command echo in C++ 

#include <iostream>
#include <cassert>

int main(int argc,char* argv[])
{
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}