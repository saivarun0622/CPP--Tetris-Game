//2. Creating grid classes and elements in the header file - Using OOPS 
#pragma once
#include<raylib.h>
#include <vector>

class GRID
{
    public:
    GRID();
    int grid [20][10];
    void Initialize();
    void Print();
    void Draw();

    //4. Moving the Blocks
    bool IsCellOutside(int row,int column);

    //6. Checking For Collisions
    bool IsCellEmpty(int row,int column);

    //7.Checking for completed rows
    int ClearFullrows();

    private:
    int rows;
    int cols;
    int cellsize;
    std::vector<Color> colors;

    //7.Checking for completed rows
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row,int numrows);
};