#include <raylib.h>

int main()
{
    InitWindow(800, 450, "Pong Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}