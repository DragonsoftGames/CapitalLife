#include "inventory/Item.hpp"

Item::~Item()
{
    delete data;
}

ItemType::~ItemType()
{
}