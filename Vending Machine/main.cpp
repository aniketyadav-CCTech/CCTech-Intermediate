#include <iostream>
#include "VM_Inventry.h"
#include "AcceptCoins.cpp"

void printInformation(vendingmachine::Inventry &inventry)
{
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "\tWelcome" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Available Cola\t($1.00) : \t" << inventry.available_cola << std::endl;
    std::cout << "Available Chips\t($0.50) : \t" << inventry.available_chips << std::endl;
    std::cout << "Available Candy\t($0.65) : \t" << inventry.available_candy << std::endl;
    std::cout << std::endl;
}

void printThankYou()
{
    std::cout << "---------------------" << std::endl;
    std::cout << "\tThank You" << std::endl;
    std::cout << "---------------------" << std::endl;
}

int main(int argc, char *argv[])
{
    vendingmachine::Biller biller;
    vendingmachine::Inventry inventry;

    initiateTransection:

    printInformation(inventry);

    biller.collectCoins();

    if (biller.getInsertedAmount() > 65)
    {
        std::cout << "Select items..." << std::endl;
        std::cout << "1.Cola" << std::endl;
        std::cout << "2.Chips" << std::endl;
        std::cout << "3.Candy" << std::endl;
        std::cout << std::endl
                  << "4.Exit" << std::endl;

        char item;
        std::cin.get(item);
        switch (item)
        {
        case '1':
        {
            unsigned int colaQuantity = 0;
            std::cout << "Enter quantity for Cola...";
            std::cin >> colaQuantity;
            if (std::cin.fail() || colaQuantity > inventry.available_cola)
                std::cout << "Invalid Quantity" << std::endl;
            else if(colaQuantity > inventry.available_cola)
                std::cout << "Out of Stock";
            else
            {
                vendingmachine::Cola cola;
                biller.returnChange(&cola, colaQuantity, biller);
            }
            break;
        }

        case '2':
        {
            unsigned int chipsQuantity = 0;
            std::cout << "Enter quantity for Chips...";
            std::cin >> chipsQuantity;
            if (std::cin.fail() || chipsQuantity > inventry.available_chips)
                std::cout << "Invalid Quantity" << std::endl;
            else if(chipsQuantity > inventry.available_chips)
                std::cout << "Out of Stock";
            else{
                vendingmachine::Chips chips;
                biller.returnChange(&chips, chipsQuantity, biller);
            }
            break;
        }

        case '3':
        {
            unsigned int candyQuantity = 0;
            std::cout << "Enter quantity for Cola...";
            std::cin >> candyQuantity;
            if (std::cin.fail())
                std::cout << "Invalid Quantity" << std::endl;
            else if(candyQuantity > inventry.available_candy)
                std::cout << "Out of Stock";
            else{
                vendingmachine::Candy candy;
                biller.returnChange(&candy, candyQuantity, biller);
            }
            break;
        }

        default:
            break;
        }
        printThankYou();
        
    }
    else
    {
        std::cout << "Insufficient amount" << std::endl;
        if (biller.getInsertedAmount() > 0)
            std::cout << "Please collect your amount : " << biller.getInsertedAmount() << " cents" << std::endl;
        biller.setInsrtedAmount(0);
    }

    char option;
    std::cout << "press y to continue" << std::endl;
    std::cin>>option;
    if(!std::cin.fail() && option == 'y')
    {
        goto initiateTransection;
    }
    else
        printThankYou();

    return EXIT_SUCCESS;
}