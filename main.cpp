#include <raylib.h>
#include <stdlib.h>
#include <string>
using namespace std;

float speed = 500.0f;

float playerOnePosY = 0;
float playerTwoPosY = 0;

int screenWidth = 800;
int screenHeight = 400;

float ballX = 400.0f;
float ballY = 200.0f;
float ballR = 5.0f;
float ballSpeedX = 200.0f;
float ballSpeedY = 200.0f;

int playerOneScore = 0;
int playerTwoScore = 0;

bool isGameStarted = false;
bool pauseMenuActive = false;

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetExitKey(KEY_NULL);
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_P))
        {
            pauseMenuActive = !pauseMenuActive;
        }
        if (pauseMenuActive)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Pause Menu", 400, 200, 50, WHITE);
            Vector2 mouse = GetMousePosition();
            Rectangle btn = {300, 100, 200, 100};
            Rectangle btn2 = {300, 250, 200, 100};
            ClearBackground(BLACK);
            DrawRectangleRec(btn, GRAY);
            DrawRectangleRec(btn2, GRAY);
            DrawText("Resume", 370, 150, 20, WHITE);
            DrawText("Quit", 370, 300, 20, WHITE);
            if (CheckCollisionPointRec(mouse, btn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                pauseMenuActive = false;
            }

            if (CheckCollisionPointRec(mouse, btn2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
            EndDrawing();
            continue;
        }
        if (!isGameStarted)
        {
            Vector2 mouse = GetMousePosition();
            Rectangle btn = {300, 100, 200, 100};
            Rectangle btn2 = {300, 250, 200, 100};
            BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangleRec(btn, GRAY);
            DrawRectangleRec(btn2, GRAY);
            DrawText("Start", 370, 150, 20, WHITE);
            DrawText("Quit", 370, 300, 20, WHITE);
            EndDrawing();
            if (CheckCollisionPointRec(mouse, btn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isGameStarted = true;
            }
            if (CheckCollisionPointRec(mouse, btn2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
            continue;

        }
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
            ballSpeedX += 100;
        }
        if (ballX > 790 && ballY >= playerTwoPosY && ballY <= playerTwoPosY + 100)
        {
            ballSpeedX *= -1;
            ballSpeedX -= 100;
        }

        if (ballX > screenWidth)
        {
            playerOneScore++;
            ballX = 400;
            ballSpeedX = 200;
        }
        if (ballX < 0)
        {
            playerTwoScore++;
            ballX = 400;
            ballSpeedX = -200;
        }

        string score = to_string(playerOneScore);
        string score2 = to_string(playerTwoScore);

        DrawText(score.data(), 350, 10, 25, WHITE);
        DrawText(score2.data(), 450, 10, 25, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}