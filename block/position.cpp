//3. Defining position header file in cpp file - for supporting the main block creating files(block.h,block.cpp & blocks.cpp).
#include "position.h"

POSITION::POSITION(int row, int column)
{
    this->row=row;
    this->column=column;
}