//4. Creating Game Class for better management and movement of the blocks.
#include <cstdlib>
#include<ctime>
#include "Gameclass.h"

GAME::GAME()
{
    grid=GRID();
    blocks=GetBlocks();
    currentBlock=GetBlock();
    nextBlock=GetBlock();
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
    currentBlock.Draw();
}

//Reads the input buffer for user inputs and moves the block
void GAME::ReadInput()
{
    int key=GetKeyPressed();
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
        break;
    case KEY_R:
        RotateBlock();
    }
}

//Moving Left
void GAME::MoveLeft()
{
    currentBlock.Move(0,-1);
    if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
    {
        currentBlock.Move(0,1);
    }
}

//Moving Right
void GAME::MoveRight()
{
    currentBlock.Move(0,1);
    if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
    {
        currentBlock.Move(0,-1);
    }
}

//Moving Down
void GAME::MoveDown()
{
    currentBlock.Move(1,0);
    if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
    {
        currentBlock.Move(-1,0);
        //6. Checking For Collisions
        LockBlock();
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
    currentBlock.Rotate();
    if(IsBlockOut() || BlockFits()==false /*(6. Checking For Collisions[BlockFits()])*/)
    {
        currentBlock.UndoRotate();
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
    nextBlock=GetBlock();
    
    //7.Checking for completed rows
    grid.ClearFullrows();
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
