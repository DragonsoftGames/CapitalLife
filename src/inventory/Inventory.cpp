#include "inventory/Inventory.hpp"

Inventory::Inventory(unsigned short p_maxSize)
    :items(std::vector<Item>()), maxSize(p_maxSize)
{

}