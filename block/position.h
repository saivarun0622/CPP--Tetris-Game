//3. Creating position header file - for supporting the main block creating files(block.h,block.cpp & blocks.cpp).
#pragma once

class POSITION
{
    public:
    POSITION(int row,int column);
    int row;
    int column;
};