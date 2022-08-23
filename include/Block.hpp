#pragma once

#define DEFAULT_BLOCK_SIZE 48

#include "Window.hpp"

class BlockData;

class BlockRenderer {
public:
    virtual void render(Window* p_window);
};

struct BlockType {
    const char* id;
    BlockRenderer* renderer;
};

struct Block {
    BlockType* type;
    BlockData* data;
    inline void render(Window* p_window) {
        type->renderer->render(p_window);
    }
};