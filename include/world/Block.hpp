#pragma once

#define DEFAULT_BLOCK_SIZE 48

#include "Window.hpp"

class BlockData
{
public:
    virtual ~BlockData() {};
};

class BlockRenderer
{
public:
    virtual ~BlockRenderer() {};

    virtual void render(Window* p_window, int p_x, int p_y) = 0;
};

struct BlockType
{
    ~BlockType();

    const char* id;
    bool isTranparent;
    BlockRenderer* renderer;
};

struct Block
{
    ~Block();

    BlockType* type;
    BlockData* data;
    inline void render(Window* p_window, int p_x, int p_y)
    {
        type->renderer->render(p_window, p_x, p_y);
    }
    inline bool isTransparent()
    {
        return type->isTranparent;
    }
};