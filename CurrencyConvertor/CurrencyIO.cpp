#include "CurrencyIO.h"

CurrencyIO::CurrencyIO(std::string filename)
{
    std::ifstream ifs(filename, std::ios::in);
    if (ifs.good())
    {
        std::string line;
        std::string curr;
        double factor;
        std::set<std::string> currencySet;
        while (std::getline(ifs, line))
        {
            std::stringstream ss;
            ss << line;
            ss >> curr;
            ss >> factor;
            currencySet.insert(curr.substr(0, 3));
            currency[curr] = factor;
        }
        for (auto currency : currencySet)
            currencyList.push_back(currency);
    }
}

void CurrencyIO::showCurrencyOptions()
{
    for (int i = 0; i < currencyList.size(); i++)
    {
        std::cout << i + 1 << ". " << currencyList[i] << std::endl;
    }
}

int CurrencyIO::chooseCurrency()
{
    showCurrencyOptions();
    int option;
selectCurrency:
    std::cout << ">";
    std::cin >> option;
    if (std::cin.fail())
        std::cout << "Please enter a valid number" << std::endl;
    if ((option < 0) || (option > (currencyList.size())))
    {
        std::cout << "The number is out of range" << std::endl;
        std::cout << "Select the input/output currency from the list" << std::endl;
        goto selectCurrency;
    }
    return --option;
}

double CurrencyIO::convertCurrency(std::string inputCurrency, std::string outputCurrency, double amount)
{
    std::string key = inputCurrency + "=>" + outputCurrency;
    double conversion = 0;
    for (int idx = 0; idx < currency.size(); idx++)
    {
        if (currency.find(key) != currency.end())
        {
            conversion = currency[key];
            conversion *= (double)amount;
        }
    }
    return conversion;
}