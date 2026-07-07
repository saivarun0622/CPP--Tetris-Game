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

    private:
    int rows;
    int cols;
    int cellsize;
    std::vector<Color> colors;
};