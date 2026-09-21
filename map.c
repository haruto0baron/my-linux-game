#include "game.h"

// 0=草(緑) 1=壁(灰) 2=水(青) 3=木(濃緑) 4=道(茶)
int map[MAP_H][MAP_W] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,3,0,0,0,0,0,1,0,0,3,0,0,0,0,0,0,1},
    {1,0,0,3,0,0,0,0,0,1,0,0,3,0,0,0,0,0,0,1},
    {1,0,0,0,0,3,0,0,0,4,0,0,0,0,0,3,0,0,0,1},
    {1,1,1,1,0,3,0,0,0,4,0,0,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,3,3,3,0,1,0,3,3,3,3,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,4,1,1,1,1,1,1,4,1,1,1,0,0,1},
    {1,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,1},
    {1,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,1},
    {1,0,0,2,2,0,4,0,0,3,3,0,0,4,0,0,2,2,0,1},
    {1,0,0,2,2,0,0,0,0,3,3,0,0,0,0,0,2,2,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void DrawMap(void) {
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            int tile = map[y][x];
            Color c;

            switch (tile) {
                case TILE_GRASS: c = DARKGREEN; break;
                case TILE_WALL:  c = GRAY;      break;
                case TILE_WATER: c = BLUE;      break;
                case TILE_TREE:  c = BROWN;     break;
                case TILE_ROAD:  c = BEIGE;     break;
                default:         c = BLACK;     break;
            }

            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE,
                          TILE_SIZE, TILE_SIZE, c);

            // 木なら緑の丸も描く（見た目用）
            if (tile == TILE_TREE) {
                DrawCircle(x * TILE_SIZE + TILE_SIZE/2,
                           y * TILE_SIZE + TILE_SIZE/2,
                           TILE_SIZE/3, GREEN);
            }

            // グリッド線（見やすさ用）
            DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE,
                               TILE_SIZE, TILE_SIZE,
                               ColorAlpha(BLACK, 0.1f));
        }
    }
}

bool IsTileSolid(int x, int y) {
    if (x < 0 || x >= MAP_W || y < 0 || y >= MAP_H)
        return true;  // 画面外も壁扱い
    int tile = map[y][x];
    return (tile == TILE_WALL || tile == TILE_WATER || tile == TILE_TREE);
}