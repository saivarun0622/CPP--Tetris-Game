//3. Defining Block classes and elements(Parent) in the cpp file - Using OOPS and Inheritance
#include "block.h"

BLOCK::BLOCK()
{
    cellsize=30;
    rotationstate=0;
    colors=CellColors();
}

//Accessed by the objects of the child class to draw different(7) tetramino blocks
void BLOCK::Draw()
{
    std::vector<POSITION> tiles=cells[rotationstate];
    for (POSITION cell : tiles)
    {
        DrawRectangle(cell.column*cellsize+1,cell.row*cellsize+1,cellsize-1,cellsize-1,colors[id]);
    }
}