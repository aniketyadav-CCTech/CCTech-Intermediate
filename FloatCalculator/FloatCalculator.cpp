// Extend the Float calculator to also support Floating point operations.

#include <float.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

void checkOverflow(){

}
template <typename T>
void printResult(T &num1,T &num2, char &opr)
{
    T result;
    try
    {
        switch(opr)
        {
            case '+' :
                result = num1+num2;
                if(num1 > 0 && num2 > 0 && result < 0) throw std::invalid_argument("Float Overflow");
                if(num1 < 0 && num2 < 0 && result > 0) throw std::invalid_argument("Float Underflow");
                break;
            case '-' :
                if(num1 < 0 && ((num1 - std::numeric_limits<T>::min())<num2)) throw std::invalid_argument("Float Underflow");
                result= num1-num2;      
                if(num1 > 0 && num2 < 0 && result < 0) throw std::invalid_argument("Float Overflow");
                break;
            case '*' :
                result= num1*num2;
                if(((num1 < 0) ^ (num2 < 0)))
                {
                    if(num1 != result/num2) throw std::invalid_argument("Float Underflow");
                }
                else if(num1 != result/num2) throw std::invalid_argument("Float Overflow");
                break;
            case '/' :
                if(num2==0) throw std::invalid_argument("Division by zero is undefined");
                result= num1/num2;
                break;
            default:
                result=0;
        }
        std::cout <<std::setprecision(15)<< "(" << num1 << ") " << opr << " (" << num2 << ") = " << result << std::endl;
    }
    catch(std::invalid_argument &err)
    {
        std::cout << err.what() << std::endl;
    }
}

int main()
{
    float num1,num2;
    char opr;
    std::cin >> num1 >> opr >> num2;
    if(std::cin.fail()) std::cout << "Invalid Input" << std::endl;
    else printResult(num1,num2,opr);
    return EXIT_SUCCESS;
}
