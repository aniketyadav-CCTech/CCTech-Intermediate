#pragma once
#include <iostream>
#include <map>
#include <string>

const unsigned int COLA_MAX_CAPACITY    = 100;
const unsigned int CHIPS_MAX_CAPACITY   = 200;
const unsigned int CANDY_MAX_CAPACITY   = 300;
const unsigned int COLA_PRICE           = 100;
const unsigned int CHIPS_PRICE          = 50;
const unsigned int CANDY_PRICE          = 65;

namespace vendingmachine
{
    class Item
    {
    public:
        Item();
        Item(std::string,unsigned int);
        std::string getItemName();
        unsigned int getCost();
    protected:
        const std::string itemName = "";
        const unsigned int cost;
    };

    class Cola : public Item
    {
    public:
        Cola();
        
        static unsigned int max_capacity;
    };

    class Chips : public Item
    {
    public:
        Chips();
        static unsigned int max_capacity;
    };

    class Candy : public Item
    {
    public:
        Candy();
        static unsigned int max_capacity;
    };

    class Inventry
    {
    public:
        Inventry();
        vendingmachine::Cola cola;
        vendingmachine::Chips chips;
        vendingmachine::Candy candy;
        std::map<int,Item> itemsMap {{1,cola},{2,chips},{3,candy}};
        unsigned int available_cola;
        unsigned int available_chips;
        unsigned int available_candy;
    };
}