#pragma once

#define DEFAULT_BLOCK_SIZE 48

#include "Camera.hpp"

class BlockData
{
public:
    virtual ~BlockData() {};
};

class BlockRenderer
{
public:
    virtual ~BlockRenderer() {};

    virtual void render(Camera& p_camera, int p_x, int p_y) = 0;
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
    inline void render(Camera& p_camera, int p_x, int p_y)
    {
        type->renderer->render(p_camera, p_x, p_y);
    }
    inline bool isTransparent()
    {
        return type->isTranparent;
    }
};