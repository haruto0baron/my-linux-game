#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "My Linux Game");
    SetTargetFPS(60);

    Vector2 ball = {400, 300};
    float radius = 30.0f;

    while (!WindowShouldClose()) {
        // 更新
        if (IsKeyDown(KEY_RIGHT)) ball.x += 4.0f;
        if (IsKeyDown(KEY_LEFT))  ball.x -= 4.0f;
        if (IsKeyDown(KEY_UP))    ball.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN))  ball.y += 4.0f;

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