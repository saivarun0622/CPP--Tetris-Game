#include<raylib.h>
#include "grid/grid.h"  //2. Creating Grid
int main()
{
//1. Setting-up the game loop


    //Creating Game Window - InitWindow()
    InitWindow(300,600,"Tetris-Game");
    Color DarkBlue={50,50,255,255};
    SetTargetFPS(90);

    //2. Creating Grid
    GRID grid=GRID();
    grid.Print();
    //2. Completed creating the grid

    //Creating infinite loop that runs until the user closes the window
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(DarkBlue);
        grid.Draw(); //2. Creating Grid

        EndDrawing();
    }
    
    CloseWindow();
}