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
            DrawRectangle(c*cellsize+11,r*cellsize+11,cellsize-1,cellsize-1,colors[cellvalue]);
        }
    }
}

//4. Moving the Blocks
//Returns flase if the block is out of the main grid
bool GRID::IsCellOutside(int row,int column)
{
    if(row>=0 && row<rows && column>=0 && column<cols)
    {
        return false;
    }
    return true;
}

bool GRID::IsCellEmpty(int row, int column)
{
    if(grid[row][column]==0)
    {
        return true;
    }
    return false;
}


//7.Checking for completed rows
//Checks if the row is completely filled by blocks or not
bool GRID::IsRowFull(int row)
{
    for (int column=0;column<cols;column++)
    {
        if(grid[row][column]==0)
        {
            return false;
        }
    }
    return true;
}

//Clears the row by setting the value to 0
void GRID::ClearRow(int row)
{
    for (int column=0;column<cols;column++)
    {
        grid[row][column]=0;
    }
}

//Moves the row down
void GRID::MoveRowDown(int row, int numrows)
{
    for (int column=0;column<cols;column++)
    {
        grid[row + numrows][column]=grid[row][column];
        grid[row][column]=0;
    }
}

//Will check all the rows from the bottom to the top to see if any row is completed and do the work accordingly if the rows are empty by calling the ClearRow() and MoveRowDown() methods.
int GRID::ClearFullrows()
{
    int completedrows=0;
    for (int row=rows-1;row>=0;row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completedrows++;
        }
        else if(completedrows>0)
        {
            MoveRowDown(row,completedrows);
        }
    }
    return completedrows;
}
