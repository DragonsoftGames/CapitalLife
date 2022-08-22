#include "Tile.hpp"

Tile::Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y)
    :chunk(p_chunk), x(p_x), y(p_y)
{

}

Tile::~Tile()
{
    
}

void Tile::update()
{

}

void Tile::render(Window* p_window, int p_x, int p_y)
{
    for(int i = lastRenderIndex; i < blockStack.size() - 1; i++)
    {
        blockStack[i].render(p_window, p_x, p_y);
    }
}

void Tile::calcLastRenderIndex()
{
    int i = blockStack.size() - 1;
    for (; i >= 0; i--)
    {
        if (!blockStack[i].isTransparent())
        {
            break;
        }
    }

    lastRenderIndex = i;
}