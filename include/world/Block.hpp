#pragma once

#define DEFAULT_BLOCK_SIZE 48

#include "Window.hpp"

class BlockData;

class BlockRenderer {
public:
    virtual void render(Window* p_window, int p_x, int p_y) = 0;
};

struct BlockType {
    const char* id;
    BlockRenderer* renderer;
};

struct Block {
    BlockType* type;
    BlockData* data;
    inline void render(Window* p_window, int p_x, int p_y) {
        type->renderer->render(p_window, p_x, p_y);
    }
};