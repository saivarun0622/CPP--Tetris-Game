//3. Creating Color header file - for returning the colors by multiple elements/classes and objects from different files.
#pragma once
#include <raylib.h>
#include<vector>

extern const Color grey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;


std::vector<Color> CellColors();