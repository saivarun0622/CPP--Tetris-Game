//4. Creating Game Class for better management and movement of the blocks.
#include<iostream>
#include <cstdlib>
#include<ctime>
#include "Gameclass.h"

GAME::GAME()
{
    grid=GRID();
    blocks=GetBlocks();
    currentBlock=GetBlock();
    nextBlock=GetBlock();

    //8. Game Over
    gameOver=false;

    //10. Score Calculations
    score=0;

    //12.Adding SFX
    InitAudioDevice();
    music=LoadMusicStream("SFX/music.mp3");
    PlayMusicStream(music);
    rotateSound=LoadSound("SFX/rotate.mp3");
    clearSound=LoadSound("SFX/clear.mp3");
    game_over=LoadSound("SFX/game_over.mp3");
}


//12.Adding SFX
//Deconstructor Specially for deinitializing the audio
GAME::~GAME()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadSound(game_over);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

//Used to return a random block out of the 7 available blocks
BLOCK GAME::GetBlock()
{
    if (blocks.empty())
    {
        blocks=GetBlocks();

    }
    srand(time(0));
    int randomIndex=rand() % blocks.size();
    BLOCK block=blocks[randomIndex];
    blocks.erase(blocks.begin()+randomIndex);
    return block;
}

//Returns vector of all the seven blocks when called
std::vector<BLOCK>GAME::GetBlocks()
{
    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void GAME::Draw()
{
    grid.Draw();
    /*11. Next Block*/
    currentBlock.Draw(11,11); //Changed as per required for drawing the blocks at the given row and column offset positions --11.
    switch(nextBlock.id)
    {
        case 3:
            nextBlock.Draw(255,285);
            break;
        case 4:
            nextBlock.Draw(255,270);
            break;
        default:
            nextBlock.Draw(270,270);
            break;
    }
    /*End of 11.*/
}

//Reads the input buffer for user inputs and moves the block
void GAME::ReadInput()
{
    int key=GetKeyPressed();
    if(gameOver && key!=0) //8. Game Over Conditional
    {
        gameOver=false;
        Reset();
    }
    switch (key)
    {
    case KEY_LEFT:
        MoveLeft();
        break;
    case KEY_RIGHT:
        MoveRight();
        break;
    case KEY_DOWN:
        MoveDown();
        UpdateScore(0,1); //10. Score Calculations
        break;
    case KEY_R:
        RotateBlock();
    }
}

//Moving Left
void GAME::MoveLeft()
{
    if(!gameOver) //8. Game Over Conditional
    {
        currentBlock.Move(0,-1);
        if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
        {
            currentBlock.Move(0,1);
        }
    }
}

//Moving Right
void GAME::MoveRight()
{
    if(!gameOver) //8. Game Over Conditional
    {
        currentBlock.Move(0,1);
        if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
        {
            currentBlock.Move(0,-1);
        }
    }
}

//Moving Down
void GAME::MoveDown()
{
    if(!gameOver) //8. Game Over Conditional
    {
        currentBlock.Move(1,0);
        if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
        {
            currentBlock.Move(-1,0);
            //6. Checking For Collisions
            LockBlock();
        }
    }
}

//Checks if the block is about to go outside of the grid and if yes, it doesn't allow it to go outside by reverting the values of its position values.
bool GAME::IsBlockOut()
{
    std::vector<POSITION> tiles=currentBlock.BlockPos();
    for(POSITION item : tiles)
    {
        if(grid.IsCellOutside(item.row,item.column))
        {
            return true;
        }
    }
    return false;
}

//Used for Rotation of the block
void GAME::RotateBlock()
{
    if(!gameOver) //8. Game Over Conditional
    {
        currentBlock.Rotate();
        if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
        {
            currentBlock.UndoRotate();
        }
        //12. Adding SFX
        else
        {
            PlaySound(rotateSound);
        }
        //End of 12
    }
}


//6. Checking For Collisions
//Used to lock the block's position on the grid once it has reached the end of the grid.
void GAME::LockBlock()
{
    std::vector<POSITION> tiles = currentBlock.BlockPos();
    for (POSITION item : tiles)
    {
        grid.grid[item.row][item.column]=currentBlock.id;
    }
    currentBlock=nextBlock;

    if(BlockFits()==false) //8. Game Over Conditional
    {
        gameOver=true;
        /*12. Adding SFX*/
        if(gameOver)
        {
            PlaySound(game_over);
        }
        /*End of 12*/
    }
    nextBlock=GetBlock();
    
    //7.Checking for completed rows
    /*grid.ClearFullrows();*/

    //10. Score Caclculations
    int rowsCompleted=grid.ClearFullrows();

    /*Not required Due to 12.
    UpdateScore(rowsCompleted,0);
    */

    //12. Adding SFX
    if(rowsCompleted>0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCompleted,0);
    }
    //End of 12
}

bool GAME::BlockFits()
{
    std::vector<POSITION> tiles = currentBlock.BlockPos();
    for (POSITION item : tiles)
    {
        if(grid.IsCellEmpty(item.row,item.column)==false)
        {
            return false;
        }
    }
    return true;
}


//8. Game Over Conditional
//Resets the game upon game over
void GAME::Reset()
{
    grid.Initialize();
    blocks=GetBlocks();
    currentBlock=GetBlock();
    nextBlock=GetBlock();
    score=0; //10. Score Calculations
}


//10. Score Calculations
//Updates the score based on number of rows cleared and down movements by the player
void GAME::UpdateScore(int rowsCompleted, int MoveDownPoints)
{
    switch (rowsCompleted)
    {
    case 1:
        score+=100;
        break;
    case 2:
        score+=300;
        break;
    case 3:
        score+=450;
        break;
    default:
        break;
    }
    score+=MoveDownPoints;
}