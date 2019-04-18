#pragma once

#include <tuple>
#include <iostream>
#include "Cell.h"
#include "EDirection.h"
#include "Graphics.h"
#include "Snake.h"

class Table
{
private:
	 int width;
	 int height;
	 Cell** cells; //https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	 //tuple<int, int> selectedCellIndex;
	 //bool isSelected(int pX, int pY);
	 //bool setSelectedCell(int pX, int pY);
	 Location getEmptyCell();
	 Graphics& gfx;
	 void drawCell(int pX, int pY, Color pColor);
	 const int CELL_WIDTH = 20;
	 bool isWithinBounds(int pX, int pY);
	 //void moveSelectedCellToEmpty();
	 Snake* activeSnake;
	 void swapSnakes();

public:
	 Table() = default;
	 Table(int pWidth, int pHeight, Graphics& gfx);
	 //void Init(int pWidth, int pHeight);
	 void MakeSymbol();
	 void Draw();
	 void Move();
	 void SetActiveSnake(Snake* pSnake);

	 EDirection MoveDirection = Right;
};
