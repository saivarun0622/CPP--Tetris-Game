//2. Implementing grid classes and elements in the cpp file - Using OOPS


// Importing grid header file
#include<iostream>
#include "grid.h"
#include "../block/colors.h"

//Setting the number of rows and columns and size of each cell.
GRID::GRID()
{
    rows=20;
    cols=10;
    cellsize=30;
    Initialize();
    colors=CellColors();
}

//Initializing all the cells to contain the value 0
void GRID::Initialize()
{
    for (int r=0;r<rows;r++)
    {
        for (int c=0;c<cols;c++)
        {
            grid[r][c]=0;
        }
    }
}

//Printing all the values of the cells of the 2-D array
void GRID::Print()
{
    for (int r=0;r<rows;r++)
    {
        for (int c=0;c<cols;c++)
        {
            std::cout<<grid[r][c]<<" ";
        }
        std::cout<<std::endl;
    }
}

//Returning the colours of the tetromino when requested/called
// std::vector<Color> GRID::CellColors()
// {
//     Color CYAN={0,255,255,255};
//     return {GRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,CYAN,BLUE};
// }
//Changed to global standalone files (created separate header and cpp files) for returning the colors as they would be used by multiple elements/classes and objects from different files.

//Drawing Grid and Grid Cells
void GRID::Draw()
{
    for (int r=0;r<rows;r++)
    {
        for(int c=0;c<cols;c++)
        {
            int cellvalue=grid[r][c];
            DrawRectangle(c*cellsize+1,r*cellsize+1,cellsize-1,cellsize-1,colors[cellvalue]);
        }
    }
}