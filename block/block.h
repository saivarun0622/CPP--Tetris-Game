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

    private:
    int cellsize;
    int rotationstate;
    std::vector<Color> colors;
};