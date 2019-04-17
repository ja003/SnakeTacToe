#pragma once
#include "Cell.h"
#include "EDirection.h"
#include<tuple>
#include <iostream>
#include "Graphics.h"

using namespace std;


class Table
{
private:
	 int width;
	 int height;
	 Cell** cells; //https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	 tuple<int, int> selectedCellIndex;
	 bool isSelected(int pX, int pY);
	 void setSelectedCell(int pX, int pY);
	 tuple<int, int> getEmptyCell();
	 Graphics& gfx;
	 void drawCell(int pX, int pY, Color pColor);
	 const int CELL_WIDTH = 20;

public:
	 Table() = default;
	 Table(int pWidth, int pHeight, Graphics& gfx);
	 //void Init(int pWidth, int pHeight);
	 void Set(char pSymbol);
	 void MoveSelectedCell(EDirection pDirection);
	 void Draw();
};
