#include <string>
#include <iostream>
#include "VM_Inventry.h"

namespace vendingmachine
{
    class Biller
    {
    public:
        void collectCoins()
        {
            std::string coin;
            std::cout << "Insert Coins (Valid coins : nickel / dime / quarter) (Invalid coin : pennie / other)" << std::endl;
            std::cout << "(press x to exit.)" << std::endl;

            while (std::getline(std::cin, coin))
            {
                if (coin == "x")
                {
                    std::cout << std::endl;
                    break;
                }
                else if (coin == "nickel")
                {
                    insertedAmount += 5;
                    nickelInserted++;
                }
                else if (coin == "dime")
                {
                    insertedAmount += 10;
                    dimeInserted++;
                }
                else if (coin == "quarter")
                {
                    insertedAmount += 25;
                    quarterInserted++;
                }
                else if (coin != "nickel" || coin != "dime" || coin != "quarter")
                {
                    std::cout << "Invalid coin" << std::endl;
                }
            }
            std::cout << "Total inserted amount : (" << quarterInserted << " quarters) + (" << dimeInserted << " dimes) + (" << nickelInserted << " nickels) = " << insertedAmount << " cents" << std::endl;
            std::cin.clear();
        }

        void returnChange(vendingmachine::Item *_item, unsigned int quantity, vendingmachine::Biller &biller) const
        {
            std::cout << "Item : " << _item->getItemName() << "\tCost : " << _item->getCost() * quantity << std::endl;
            if (biller.getInsertedAmount() < _item->getCost() * quantity)
            {
                std::cout << "Insufficient Amount" << std::endl;
                return;
            }
            else
            {
                std::cout << "Please Collect your " << quantity << " " << _item->getItemName() << std::endl;
                for(auto item:inventry.)
                std::cout << "Please collect remaining " << biller.insertedAmount - _item->getCost() * quantity << " cents" << std::endl;
                biller.setInsrtedAmount(0);
            }
        }

        unsigned int getInsertedAmount() const
        {
            return insertedAmount;
        }
        void setInsrtedAmount(const unsigned int &amount)
        {
            insertedAmount = amount;
        }

    private:
        unsigned int insertedAmount = 0;
        unsigned int nickelInserted = 0;
        unsigned int dimeInserted = 0;
        unsigned int quarterInserted = 0;
    };
}