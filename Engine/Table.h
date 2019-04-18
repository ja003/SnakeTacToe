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
public:
	 Table() = default;
	 Table(int pWidth, int pHeight, int pWinPointsCount, Graphics& gfx);
	 //void Init(int pWidth, int pHeight);
	 void MakeSymbol();
	 void Draw();
	 void Move();
	 void SetActiveSnake(Snake* pSnake);
	 void SetMoveDirection(EDirection pDirection);
	 bool GetGameEnded()
	 {
		  return gameEnded;
	 }
private:
	 EDirection moveDirection = Right;
	 int width;
	 int height;
	 int winPointsCount;
	 Cell** cells; //https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	 Graphics& gfx;
	 const int CELL_WIDTH = 20;
	 Snake* activeSnake;
	 bool gameEnded = false;
private:
	 Location GetEmptyCell();
	 void DrawCell(int pX, int pY, Color pColor);
	 bool IsWithinBounds(Location pLocation);
	 void SwapSnakes();
	 Cell* GetCell(Location pLocation)
	 {
		  if(!IsWithinBounds(pLocation))
				return nullptr;

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
	 void SetGoodDirection();
	 
	 bool CheckWin();
	 bool CheckWinInDirection(EDirection pDirection);
	 int GetPointsInDirection(Location pStart, EDirection pDirection, bool pRecursionFlag = false);
	 void Win()
	 {
		  gameEnded = true;
	 }
};
