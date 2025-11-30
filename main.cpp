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

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong Game");

    while (!WindowShouldClose())
    {
        if(!isGameStarted){
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Press SPACE to start", 250, 180, 20, WHITE);
            EndDrawing();
            if(IsKeyPressed(KEY_SPACE)){
                isGameStarted = true;
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