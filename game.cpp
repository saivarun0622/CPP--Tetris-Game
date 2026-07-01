#include<raylib.h>
int main()
{
//1. Setting-up the game loop

    
    //Creating Game Window - InitWindow()
    InitWindow(300,600,"Tetris-Game");
    Color Grey={127,127,127,100};
    SetTargetFPS(90);

    //Creating infinite loop that runs until the user closes the window
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(Grey);

        EndDrawing();
    }
    
    CloseWindow();
}