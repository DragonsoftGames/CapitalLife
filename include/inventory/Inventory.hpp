#pragma once

#include <vector>

#include "inventory/Item.hpp"

class Inventory
{
public:
    Inventory(unsigned short p_maxSize);

private:
    std::vector<Item> items;
    unsigned short maxSize;
};