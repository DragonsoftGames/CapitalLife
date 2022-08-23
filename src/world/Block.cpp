#include "world/Block.hpp"

Block::~Block()
{
    delete data;
}

BlockType::~BlockType()
{
    delete renderer;
}