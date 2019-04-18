#pragma once

#include <tuple>
#include <iostream>
#include <assert.h>
#include "Cell.h"
#include "EDirection.h"
#include "Graphics.h"
#include "Snake.h"

class Table
{
public:
	 EDirection MoveDirection = Right;
public:
	 Table() = default;
	 Table(int pWidth, int pHeight, Graphics& gfx);
	 //void Init(int pWidth, int pHeight);
	 void MakeSymbol();
	 void Draw();
	 void Move();
	 void SetActiveSnake(Snake* pSnake);


private:
	 int width;
	 int height;
	 Cell** cells; //https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	 Graphics& gfx;
	 const int CELL_WIDTH = 20;
	 Snake* activeSnake;

private:
	 Location GetEmptyCell();
	 void DrawCell(int pX, int pY, Color pColor);
	 bool IsWithinBounds(Location pLocation);
	 void SwapSnakes();
	 Cell* GetCell(Location pLocation)
	 {
		  assert(pLocation.x >= 0);
		  assert(pLocation.x < width);
		  assert(pLocation.y >= 0);
		  assert(pLocation.y < height);

		  //check!
		  return &cells[pLocation.x][pLocation.y];
	 }
	 int GetNonEmptyCellCount()
	 {
		  int count = 0;
		  for(int y = 0; y < width; y++)
		  {
				for(int x = 0; x < height; x++)
				{
					 Cell* cell = &cells[x][y];
					 if(!cell->IsEmpty())
						  count++;
				}
		  }
		  return count;
	 }
};
