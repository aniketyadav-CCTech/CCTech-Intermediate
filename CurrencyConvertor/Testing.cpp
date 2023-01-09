#include <iostream>
#include <cassert>
#include <cmath>
#include "CurrencyIO.h"

using namespace std;

int main(int argc, char* argv[])
{
    CurrencyIO io("conversion.txt");

    // for list of currencies    
    assert(io.currencyList == (vector<string>{"AUD","CHF","CNY","EUR","GBP","INR","JPY","SGD","USD"}));

    // INR to USD conversion
    assert(io.convertCurrency("INR","USD",10)==0.121);
    assert(round(io.convertCurrency("USD","INR",0.121))==10);

    return EXIT_SUCCESS;
}