#include <iostream>
#include<raylib.h>
#include "GameClass/Gameclass.h"

/*These lines of code were written for testing purpose before including the GameClass files.
#include "grid/grid.h"  //2. Creating Grid
#include "block/blocks.cpp" //3. Creating Blocks
*/

//6. Checking For Collisions
double LastUpdateTime=0;
bool EventTriggered(double interval)
{
    double CurrentTime=GetTime();
    if(CurrentTime-LastUpdateTime>=interval)
    {
        LastUpdateTime=CurrentTime;
        return true;
    }
    return false;
}

int main()
{
//1. Setting-up the game loop


    //Creating Game Window - InitWindow()
    InitWindow(300,600,"Tetris-Game");
    Color DarkBlue={50,50,255,255};
    SetTargetFPS(90);


    /*These lines of code were written for testing purpose before including the GameClass files.
    //2. Creating Grid
    GRID grid=GRID();
    grid.Print();
    //2. Completed creating the Grid

    //3. Creating Blocks
    OBlock oblock = OBlock();
    //3. Completed creating the Blocks
    */
   GAME game=GAME();


    //Creating infinite loop that runs until the user closes the window
    while (WindowShouldClose()==false)
    {
        game.ReadInput();
        if(EventTriggered(0.8))
        {
            game.MoveDown();
        }
        BeginDrawing();
        ClearBackground(DarkBlue);
        game.Draw();


        /* These lines of code were written for testing purpose before including the GameClass files.
        grid.Draw(); //2. Creating Grid
        oblock.Draw();//3. Creating Blocks : L-Block
        */


        EndDrawing();
    }
    
    CloseWindow();
}