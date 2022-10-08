// USE #define CALI_DEBUG

// DBGE = Debug Enable
#ifdef CALI_DEBUG
#define CALI_DEBUG_TILECOL
#endif

/* TILE COL */
#ifdef CALI_DEBUG_TILECOL

#define CALI_DEBUG_TILECOL_INIT \
    std::vector<std::tuple<int, int, bool>> calidbg_tilecol;

#define CALI_DEBUG_TILECOL_CLEAR \
    calidbg_tilecol.clear();

#define CALI_DEBUG_TILECOL_SET(tile) \
    calidbg_tilecol.push_back(std::tuple(tile->x + tile->chunk.x * CHUNK_SIZE, tile->y + tile->chunk.y * CHUNK_SIZE, tile->collision(entity) == nullptr));

#define CALI_DEBUG_TILECOL_RENDER                                                                                                                          \
    for (auto t : calidbg_tilecol)                                                                                                                         \
    {                                                                                                                                                      \
        camera.drawRect(std::get<0>(t) * DEFAULT_BLOCK_SIZE, std::get<1>(t) * DEFAULT_BLOCK_SIZE, DEFAULT_BLOCK_SIZE, DEFAULT_BLOCK_SIZE, std::get<2>(t)); \
    }

#else

#define CALI_DEBUG_TILECOL_INIT
#define CALI_DEBUG_TILECOL_CLEAR
#define CALI_DEBUG_TILECOL_SET(tile)
#define CALI_DEBUG_TILECOL_RENDER

#endif