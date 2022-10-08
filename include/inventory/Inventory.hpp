#pragma once

#include <vector>

#include "inventory/Item.hpp"

struct Inventory
{
public:
    Inventory(unsigned short p_maxSize);

    void addItem(Item p_item);

private:
    std::vector<Item> items;
    unsigned short size;
    unsigned short maxSize;
};