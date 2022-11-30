// Find the square root of a number and handle the invalid inputs using exception handling.
#include <iostream>
#include <cassert>
#include <cmath>

double squareRoot(const double& num)
{
    double result;
    if(num < 0)
        throw "Negative numbers doesn't have real square roots";
    else
         return sqrt((num));
}

int main(int argc, char* argv[])
{
    double num;
    std::cout << "Enter a number : ";
    std::cin >> num;
    if(std::cin.fail())
    {
        std::cerr << "Invalid Input" << std::endl;
        exit(EINVAL);
    }
    try{
        if(double root = squareRoot(num))
        std::cout << "Square root of " << num << " is " << root <<std::endl;
    }
    catch(const char* exc)
    {
        std::cout << "Exception Occured : " << exc << std::endl;
    }
    
    return EXIT_SUCCESS;
}