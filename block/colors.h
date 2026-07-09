//3. Creating Color header file - for returning the colors by multiple elements/classes and objects from different files.
#pragma once
#include <raylib.h>
#include<vector>

extern const Color grey; //9. Creating The UI - updated existing color
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color white; //9. Creating The UI - Created new colors
extern const Color black; //9. Creating The UI - Created new colors


std::vector<Color> CellColors();