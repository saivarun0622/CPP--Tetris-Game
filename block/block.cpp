//3. Defining Block classes and elements(Parent) in the cpp file - Using OOPS and Inheritance
#include "block.h"

BLOCK::BLOCK()
{
    cellsize=30;
    rotationstate=0;
    colors=CellColors();

    //4. Moving the Blocks
    rowOffset=0;
    columnOffset=0;
}

//Accessed by the objects of the child class to draw different(7) tetramino blocks
/*11. Next Block*/
void BLOCK::Draw(int x_offset,int y_offset) //Changed as per required for drawing the blocks at the given row and column offset positions --11.
/*End of 11*/
{
    std::vector<POSITION> tiles=BlockPos();
    for (POSITION cell : tiles)
    {
        /*11. Next Block*/
        DrawRectangle(cell.column*cellsize+x_offset,cell.row*cellsize+y_offset,cellsize-1,cellsize-1,colors[id]); //Changed as per required for drawing the blocks at the given row and column offset positions --11.
        /*End of 11*/
    }
}


//4. Moving the Blocks

//Used to change the offset of the rows and columns 
void BLOCK::Move(int rows, int columns)
{
    rowOffset+=rows;
    columnOffset+=columns;
}

//Used to move the grid containing the tetramino blocks based on the changed offset row and column values
std::vector<POSITION> BLOCK::BlockPos()
{
    std::vector<POSITION>tiles=cells[rotationstate];
    std::vector<POSITION>movedTiles;
    for(POSITION cell:tiles)
    {
        POSITION newPos=POSITION(cell.row+=rowOffset,cell.column+=columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

//5.Rotating the Blocks
//Rotates the Block
void BLOCK::Rotate()
{
    rotationstate++;
    if(rotationstate==cells.size())
    {
        rotationstate=0;
    }
}

//Undoes/Reverses the rotation of the Block
void BLOCK::UndoRotate()
{
    rotationstate--;
    if(rotationstate==-1)
    {
        rotationstate=cells.size()-1;
    }
}
