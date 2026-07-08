//3. Creating and Defining Block classes and elements(Child) in the cpp file - Using OOPS and Inheritance
#include "block.h"
#include "position.h"


//Defining the child Blocks

//L-Block
class LBlock : public BLOCK
{
    public:
    LBlock()
    {
        id=1;
        cells[0]={POSITION(0,2),POSITION(1,0),POSITION(1,1),POSITION(1,2)};
        cells[1]={POSITION(0,1),POSITION(1,1),POSITION(2,1),POSITION(2,2)};
        cells[2]={POSITION(1,0),POSITION(1,1),POSITION(1,2),POSITION(2,0)};
        cells[3]={POSITION(0,0),POSITION(0,1),POSITION(1,1),POSITION(2,1)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(0,3);
    }
};

//J-Block
class JBlock : public BLOCK
{
    public:
    JBlock()
    {
        id=2;
        cells[0]={POSITION(0,0),POSITION(1,0),POSITION(1,1),POSITION(1,2)};
        cells[1]={POSITION(0,1),POSITION(0,2),POSITION(1,1),POSITION(2,1)};
        cells[2]={POSITION(1,0),POSITION(1,1),POSITION(1,2),POSITION(2,2)};
        cells[3]={POSITION(0,1),POSITION(1,1),POSITION(2,0),POSITION(2,1)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(0,3);
    }
};

//I-Block
class IBlock : public BLOCK
{
    public:
    IBlock()
    {
        id=3;
        cells[0]={POSITION(1,0),POSITION(1,1),POSITION(1,2),POSITION(1,3)};
        cells[1]={POSITION(0,2),POSITION(1,2),POSITION(2,2),POSITION(3,2)};
        cells[2]={POSITION(2,0),POSITION(2,1),POSITION(2,2),POSITION(2,3)};
        cells[3]={POSITION(0,1),POSITION(1,1),POSITION(2,1),POSITION(3,1)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(-1,3);
    }
};

//O-Block
class OBlock : public BLOCK
{
    public:
    OBlock()
    {
        id=4;
        cells[0]={POSITION(0,0),POSITION(0,1),POSITION(1,0),POSITION(1,1)};
        cells[1]={POSITION(0,0),POSITION(0,1),POSITION(1,0),POSITION(1,1)};
        cells[2]={POSITION(0,0),POSITION(0,1),POSITION(1,0),POSITION(1,1)};
        cells[3]={POSITION(0,0),POSITION(0,1),POSITION(1,0),POSITION(1,1)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(0,4);
    }
};

//S-Block
class SBlock : public BLOCK
{
    public:
    SBlock()
    {
        id=5;
        cells[0]={POSITION(0,1),POSITION(0,2),POSITION(1,0),POSITION(1,1)};
        cells[1]={POSITION(0,1),POSITION(1,1),POSITION(1,2),POSITION(2,2)};
        cells[2]={POSITION(1,1),POSITION(1,2),POSITION(2,0),POSITION(2,1)};
        cells[3]={POSITION(0,0),POSITION(1,0),POSITION(1,1),POSITION(2,1)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(0,3);
    }
};

//T-Block
class TBlock : public BLOCK
{
    public:
    TBlock()
    {
        id=6;
        cells[0]={POSITION(0,1),POSITION(1,0),POSITION(1,1),POSITION(1,2)};
        cells[1]={POSITION(0,1),POSITION(1,1),POSITION(1,2),POSITION(2,1)};
        cells[2]={POSITION(1,0),POSITION(1,1),POSITION(1,2),POSITION(2,1)};
        cells[3]={POSITION(0,1),POSITION(1,0),POSITION(1,1),POSITION(2,1)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(0,3);
    }
};

//Z-Block
class ZBlock : public BLOCK
{
    public:
    ZBlock()
    {
        id=7;
        cells[0]={POSITION(0,0),POSITION(0,1),POSITION(1,1),POSITION(1,2)};
        cells[1]={POSITION(0,2),POSITION(1,1),POSITION(1,2),POSITION(2,1)};
        cells[2]={POSITION(1,0),POSITION(1,1),POSITION(2,1),POSITION(2,2)};
        cells[3]={POSITION(0,1),POSITION(1,0),POSITION(1,1),POSITION(2,0)};
        
        //4. Moving the Blocks
        //Used this method in child class constructor to spawn the tetramino block from the middle of the main grid
        Move(0,3);
    }
};