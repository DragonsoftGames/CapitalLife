#include "inventory/Inventory.hpp"

Inventory::Inventory(unsigned short p_maxSize)
    : items(std::vector<Item>()), maxSize(p_maxSize), size(0)
{
}

void Inventory::addItem(Item p_item)
{
    size += p_item.getSize();
    items.push_back(std::move(p_item));
}