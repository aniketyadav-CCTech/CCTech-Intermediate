#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>

class CurrencyIO
{
public:
    CurrencyIO(std::string);
    int chooseCurrency();
    double convertCurrency(std::string, std::string, double);
    
    std::vector<std::string> currencyList;
    std::string inputCurrency, outputCurrency;

private:
    void showCurrencyOptions();

    std::map<std::string, double> currency;
};