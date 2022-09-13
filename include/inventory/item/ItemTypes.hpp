#pragma once

#include "inventory/Item.hpp"

namespace ItemTypes
{
    inline ItemType* stick;

    inline void setup()
    {
        stick = new ItemType{"cali:stick", 1};
    }

    inline void cleanup()
    {
        delete stick;
    }
}