//3. Defining Color header file in cpp file - for returning the colors by multiple elements/classes and objects from different files.
#include "colors.h"

const Color grey={75,75,75,255};  //9. Creating The UI - updated existing color
const Color green={47,230,23,255};
const Color red={232,18,18,255};
const Color orange={226,116,17,255};
const Color yellow={237,234,4,255};
const Color purple={166,0,247,255};
const Color cyan={21,204,209,255};
const Color blue={13,64,216,255};
const Color white={255,255,255,255};  //9. Creating The UI - Created new colors
const Color black={0,0,0,255};  //9. Creating The UI - Created new colors

//Returning the colours of the tetromino when requested/called
std::vector<Color> CellColors()
{
    return {grey,green,red,orange,yellow,purple,cyan,blue};
}