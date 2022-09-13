#include "inventory/Inventory.hpp"

Inventory::Inventory(unsigned short p_maxSize)
    :items(std::vector<Item>()), maxSize(p_maxSize)
{
}

void Inventory::addItem(Item p_item)
{
    items.push_back(std::move(p_item));
}