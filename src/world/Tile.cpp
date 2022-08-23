#include "world/World.hpp"

Tile::Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y)
    :chunk(p_chunk), x(p_x), y(p_y)
{

}

Tile::~Tile()
{
    
}

void Tile::addBlock(Block* block)
{
    blockStack.push_back(block);
    calcFirstRenderIndex();
}

void Tile::addBlockUnsafe(Block* block)
{
    blockStack.push_back(block);
}

Block* Tile::getBlock()
{
    if (!(blockStack.size() > 0))
    {
        return nullptr; // TODO: Maybe Air Block?
    }
    return blockStack.back();
}

Block* Tile::removeBlock()
{
    if (!(blockStack.size() > 0))
    {
        return nullptr; // TODO: Maybe Air Block?
    }
    Block* result = blockStack.back();
    blockStack.pop_back();
    calcFirstRenderIndex();
    return result;
}

void Tile::update()
{

}

void Tile::render(Window* p_window, int p_x, int p_y)
{
    for(int i = firstRenderIndex; i < blockStack.size(); i++)
    {
        blockStack[i]->render(p_window, p_x, p_y);
    }
}

void Tile::calcFirstRenderIndex()
{
    int i = blockStack.size() - 1;
    for (; i > 0; i--)
    {
        if (!blockStack[i]->isTransparent())
        {
            break;
        }
    }

    firstRenderIndex = i;
}