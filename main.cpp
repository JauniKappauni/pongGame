#include <raylib.h>

float speed = 200.0f;

float playerOnePosY = 0;
float playerTwoPosY = 0;

int screenWidth = 800;
int screenHeight = 400;

float ballX = 400.0f;
float ballY = 200.0f;
float ballR = 5.0f;
float ballSpeedX = 200.0f;
float ballSpeedY = 200.0f;

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

        ballX += ballSpeedX * dt;
        ballY += ballSpeedY * dt;

        DrawCircle(ballX, ballY, ballR, WHITE);

        if (ballY < 0 || ballY > screenHeight)
        {
            ballSpeedY *= -1;
        }
        if (ballX < 10 && ballY >= playerOnePosY && ballY <= playerOnePosY + 100)
        {
            ballSpeedX *= -1;
        }
        if (ballX > 790 && ballY >= playerTwoPosY && ballY <= playerTwoPosY + 100)
        {
            ballSpeedX *= -1;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}