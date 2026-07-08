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
    }
}

//Moving Left
void GAME::MoveLeft()
{
    currentBlock.Move(0,-1);
    if(IsBlockOut())
    {
        currentBlock.Move(0,1);
    }
}

//Moving Right
void GAME::MoveRight()
{
    currentBlock.Move(0,1);
    if(IsBlockOut())
    {
        currentBlock.Move(0,-1);
    }
}

//Moving Down
void GAME::MoveDown()
{
    currentBlock.Move(1,0);
    if(IsBlockOut())
    {
        currentBlock.Move(-1,0);
    }
}

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