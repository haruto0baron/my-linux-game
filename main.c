#include "game.h"

int main(void) {
    InitWindow(SCREEN_W, SCREEN_H, "RPG - Tilemap");
    SetTargetFPS(60);

    Player player;
    InitPlayer(&player);

    // 2Dカメラ（プレイヤーを中心に追従）
    Camera2D camera = {0};
    camera.zoom = 1.5f;

    while (!WindowShouldClose()) {
        // 更新
        UpdatePlayer(&player);

        // カメラをプレイヤー位置に合わせる
        camera.target = (Vector2){
            player.x * TILE_SIZE + TILE_SIZE / 2.0f,
            player.y * TILE_SIZE + TILE_SIZE / 2.0f
        };
        camera.offset = (Vector2){SCREEN_W / 2.0f, SCREEN_H / 2.0f};

        // 描画
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);   // カメラ適用開始
        DrawMap();
        DrawPlayer(&player);
        EndMode2D();           // カメラ適用終了

        // UI（カメラ外に表示）
        DrawText("RPG Tilemap Demo", 10, 10, 20, WHITE);
        DrawText("WASD / Arrow keys to move", 10, 35, 16, GRAY);
        DrawText(TextFormat("Player: %d, %d", player.x, player.y),
                 10, 55, 16, YELLOW);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}