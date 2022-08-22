#include "Block.hpp"

Block::Block(SDL_Texture* p_tex, bool p_transparent)
    :texture(p_tex), transparent(p_transparent)
{
    
}

void Block::render(Window* p_window, int p_x, int p_y)
{
    p_window->render(texture, {0, 0, 32, 32}, {DEFAULT_BLOCK_SIZE*p_x, DEFAULT_BLOCK_SIZE*p_y, DEFAULT_BLOCK_SIZE, DEFAULT_BLOCK_SIZE});
}

bool Block::isTransparent()
{
    return transparent;
}