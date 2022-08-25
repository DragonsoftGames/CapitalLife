#include "world/World.hpp"

Tile::Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y)
    :chunk(p_chunk), x(p_x), y(p_y), blockStack(std::deque<Block*>())
{
    
}

Tile::~Tile()
{
    for (auto const& block : blockStack)
    {
        delete block;
    }
    blockStack.clear();
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
    if (blockStack.size() <= 0) return;
}

void Tile::render(Window* p_window, int p_x, int p_y)
{
    if (blockStack.size() <= 0) return;
    for(std::deque<Block*>::size_type i = firstRenderIndex; i < blockStack.size(); i++)
    {
        blockStack[i]->render(p_window, p_x, p_y);
    }
}

void Tile::calcFirstRenderIndex()
{
    std::deque<Block*>::size_type i = blockStack.size() - 1;
    for (; i > 0; i--)
    {
        if (!blockStack[i]->isTransparent())
        {
            break;
        }
    }

    firstRenderIndex = i;
}