#include "raylib.h"

int main(void) {
    // リサイズ可
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    
    InitWindow(800, 600, "My Linux Game");
    SetTargetFPS(60);
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    Vector2 ball = {width / 2, height / 2};
    float radius = 30.0f;

    while (!WindowShouldClose()) {
        // 更新

        // ウインドウ

        width = GetScreenWidth();
        height = GetScreenHeight();

        //  キー

        if (IsKeyDown(KEY_RIGHT)) ball.x += 4.0f;
        if (IsKeyDown(KEY_LEFT))  ball.x -= 4.0f;
        if (IsKeyDown(KEY_UP))    ball.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN))  ball.y += 4.0f;

        // もしはみ出てるなら修正
        if (ball.x < 0) ball.x = 0;
        if (ball.x > width) ball.x = width;
        if (ball.y < 0) ball.y = 0;
        if (ball.y > height) ball.y = height;

        // 描画
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(ball, radius, RED);
        DrawText("move: arrow", 10, 10, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}