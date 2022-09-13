#pragma once

class ItemData
{
public:
    virtual ~ItemData() {};
};

struct ItemType
{
    ~ItemType();

    const char* id;
    unsigned short size;
};

struct Item
{
    ~Item();

    ItemType* type;
    ItemData* data;

    inline unsigned short getSize()
    {
        return type->size;
    }
};