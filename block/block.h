//3. Creating Block classes and elements(Parent) in the header file - Using OOPS and Inheritance
#pragma once
#include<vector>
#include <map>
#include "position.h"
#include "colors.h"

//Defining the Parent 'Block' Class to be used as a default templates by different child 'Blocks' Classees.
class BLOCK
{
    public:
    BLOCK();
    void Draw();
    int id;
    std::map<int, std::vector<POSITION>>cells;

    //4. Moving the Blocks
    void Move(int rows, int columns);
    std::vector<POSITION> BlockPos();

    //5.Rotating the Blocks
    void Rotate();
    void UndoRotate();

    private:
    int cellsize;
    int rotationstate;
    std::vector<Color> colors;

    //4. Moving the Blocks
    int rowOffset;
    int columnOffset;
};