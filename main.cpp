#include <raylib.h>

float speed = 100.0f;

float playerOnePosY = 0;
float playerTwoPosY = 0;

int screenWidth = 800;
int screenHeight = 400;

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong Game");

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(10, playerOnePosY, 10, playerOnePosY + 100, WHITE);
        DrawLine(790, playerTwoPosY, 790, playerTwoPosY + 100, WHITE);

        if (IsKeyDown(KEY_W) && playerOnePosY > 0)
        {
            playerOnePosY -= speed * dt;
        }
        if (IsKeyDown(KEY_S) && playerOnePosY + 100 < screenHeight)
        {
            playerOnePosY += speed * dt;
        }
        if (IsKeyDown(KEY_UP) && playerTwoPosY > 0)
        {
            playerTwoPosY -= speed * dt;
        }
        if (IsKeyDown(KEY_DOWN) && playerTwoPosY + 100 < screenHeight)
        {
            playerTwoPosY += speed * dt;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}