#include "VM_Inventry.h"

unsigned int vendingmachine::Cola::max_capacity = COLA_MAX_CAPACITY;
unsigned int vendingmachine::Candy::max_capacity = CANDY_MAX_CAPACITY;
unsigned int vendingmachine::Chips::max_capacity = CHIPS_MAX_CAPACITY;

vendingmachine::Inventry::Inventry():available_cola(Cola::max_capacity),available_chips(Chips::max_capacity),available_candy(Candy::max_capacity)
{
}

vendingmachine::Item::Item(std::string name = "", unsigned int cost = 0) : itemName(name), cost(cost)
{
}

std::string vendingmachine::Item::getItemName()
{
    return itemName;
}

unsigned int vendingmachine::Item::getCost()
{
    return cost;
}

vendingmachine::Cola::Cola() : Item("Cola", 100)
{
}

vendingmachine::Chips::Chips() : Item("Chips", 50)
{
}

vendingmachine::Candy::Candy() : Item("Candy", 65)
{
}
