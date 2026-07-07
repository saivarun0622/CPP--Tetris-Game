#include<raylib.h>
#include "grid/grid.h"  //2. Creating Grid
#include "block/blocks.cpp" //3. Creating Blocks
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
    //2. Completed creating the Grid

    //3. Creating Blocks
    LBlock lblock = LBlock();
    //3. Completed creating the Blocks

    //Creating infinite loop that runs until the user closes the window
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(DarkBlue);
        grid.Draw(); //2. Creating Grid
        lblock.Draw();//3. Creating Blocks : L-Block
        EndDrawing();
    }
    
    CloseWindow();
}