//4. Creating Game Class for better management and movement of the blocks.
#pragma once
#include<vector>
#include "../grid/grid.h"
#include "../block/blocks.cpp"

class GAME
{
    public:
    GAME();
    BLOCK GetBlock();
    std::vector<BLOCK> GetBlocks();
    void Draw();
    void ReadInput();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    GRID grid;
    
    private:
    bool IsBlockOut();
    std::vector<BLOCK> blocks;
    BLOCK currentBlock;
    BLOCK nextBlock;

    //5.Rotating the Blocks
    void RotateBlock();
};