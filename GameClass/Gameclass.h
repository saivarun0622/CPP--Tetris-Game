//4. Creating Game Class for better management and movement of the blocks.
#pragma once
#include<vector>
#include "../grid/grid.h"
#include "../block/blocks.cpp"

class GAME
{
    public:
    GAME();
    void Draw();
    void ReadInput();
    void MoveDown();
    
    //8. Game Over
    bool gameOver;
    
    //10. Score Calculations
    int score; 
    
    private:
    BLOCK GetBlock();
    std::vector<BLOCK> GetBlocks();
    void MoveLeft();
    void MoveRight();
    bool IsBlockOut();
    GRID grid;
    std::vector<BLOCK> blocks;
    BLOCK currentBlock;
    BLOCK nextBlock;
    
    //5.Rotating the Blocks
    void RotateBlock();

    //6. Checking For Collisions
    void LockBlock();
    bool BlockFits();

    //8. Game Over Conditional
    void Reset();

    //10. Score Calculations
    void UpdateScore(int rowsCompleted, int MoveDownPoints);
};