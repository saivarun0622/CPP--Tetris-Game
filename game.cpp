#include <iostream>
#include<raylib.h>
#include "GameClass/Gameclass.h"
#include "block/colors.h"

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
    InitWindow(500,620,"Tetris-Game"); //9. Creating The UI

    /*
    Color DarkBlue={50,50,255,255};  Removed as the required color is take directly from the colors.cpp and colors.h
    */

    SetTargetFPS(90);


    Font font = LoadFontEx("C:/Users/saiva/AppData/Local/Microsoft/Windows/Fonts/Caprasimo-Regular.ttf",64,0,0); //9. Creating The UI



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
        UpdateMusicStream(game.music); //12. Adding SFX
        game.ReadInput();
        if(EventTriggered(0.8))
        {
            game.MoveDown();
        }
        BeginDrawing();
        ClearBackground(black);

        DrawTextEx(font,"Score",{360,15},38,1,white); //9. Creating The UI
        DrawTextEx(font,"Next Block",{320,175},33,1,white); //9. Creating The UI
        if(game.gameOver)
        {
            PauseMusicStream(game.music); //12. Adding SFX
            DrawTextEx(font,"GAME OVER",{315,450},29,1,white); //9. Creating The UI
        }
        else
        {
            ResumeMusicStream(game.music);//12. Adding SFX
        }
        DrawRectangleRounded({320,65,170,60},0.5 ,9,grey); //9. Creating The UI
        
        char scoreText[10]; //10. Score Calculations
        sprintf(scoreText,"%d",game.score); //10. Score Calculations
        Vector2 textSize=MeasureTextEx(font,scoreText,35,1); //10. Score Calculations
        DrawTextEx(font,scoreText,{320+(170-textSize.x)/2,65+(60-textSize.y)/2},35,1,white); //10. Score Calculations

        DrawRectangleRounded({320,225,170,150},0.5,9,grey); //9. Creating The UI
        game.Draw();


        /* These lines of code were written for testing purpose before including the GameClass files.
        grid.Draw(); //2. Creating Grid
        oblock.Draw();//3. Creating Blocks : L-Block
        */


        EndDrawing();
    }
    
    CloseWindow();
}