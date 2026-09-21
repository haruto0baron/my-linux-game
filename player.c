#include "game.h"

void InitPlayer(Player *p) {
    // マップ中央付近に配置
    p->x = 5;
    p->y = 5;
}

void UpdatePlayer(Player *p) {
    // IsKeyPressed で1マスずつ移動（連続移動しない）
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
        if (!IsTileSolid(p->x + 1, p->y)) p->x++;
    }
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
        if (!IsTileSolid(p->x - 1, p->y)) p->x--;
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        if (!IsTileSolid(p->x, p->y + 1)) p->y++;
    }
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
        if (!IsTileSolid(p->x, p->y - 1)) p->y--;
    }
}

void DrawPlayer(const Player *p) {
    int px = p->x * TILE_SIZE + TILE_SIZE / 2;
    int py = p->y * TILE_SIZE + TILE_SIZE / 2;

    // 自機（赤い円 + 目印）
    DrawCircle(px, py, TILE_SIZE / 3, RED);
    DrawCircle(px - 4, py - 4, 3, WHITE);  // 目
    DrawCircle(px + 4, py - 4, 3, WHITE);  // 目
}