#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#define SCREEN_W 800
#define SCREEN_H 600
#define TILE_SIZE 40
#define MAP_W 20
#define MAP_H 15

typedef enum {
    TILE_GRASS = 0,
    TILE_WALL,
    TILE_WATER,
    TILE_TREE,
    TILE_ROAD
} TileType;

typedef struct {
    int x, y;       // タイル座標
} Player;

// map.c
extern int map[MAP_H][MAP_W];
void DrawMap(void);
bool IsTileSolid(int x, int y);

// player.c
void InitPlayer(Player *p);
void UpdatePlayer(Player *p);
void DrawPlayer(const Player *p);

#endif