#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CurrencyIO.h"

int main(int argc, char *argv[])
{
    char continueOption;
    do
    {
        std::string inputCurrency, outputCurrency;
        double inputAmount;
        CurrencyIO io("conversion.txt");

        std::cout << "Welcome to CCTech Currency converter:" << std::endl;
        
        std::cout << "Select the input currency from the list" << std::endl;
        int option = io.chooseCurrency();
        inputCurrency = io.currencyList[option];
        auto it = std::find(io.currencyList.begin(), io.currencyList.end(), io.currencyList[option]);
        io.currencyList.erase(it);

        std::cout << std::endl;
        std::cout << "Select the output currency from the list" << std::endl;
        option = io.chooseCurrency();
        outputCurrency = io.currencyList[option];

        std::cout << std::endl;
        std::cout << "Please enter the amount" << std::endl;
        std::cout << ">";
        std::cin >> inputAmount;

        std::cout << std::endl;
        double outputAmount = io.convertCurrency(inputCurrency, outputCurrency, inputAmount);
        std::cout << inputAmount << " " << inputCurrency << " would be " << outputAmount << " " << outputCurrency << " on 2023-01-06" << std::endl;
        std::cout << "Do you wish to continue with another conversion (Y/N)" << std::endl;
        std::cin >> continueOption;
    } while (continueOption == 'Y');

    return EXIT_SUCCESS;
}