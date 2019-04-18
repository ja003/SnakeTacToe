#pragma once
#include "Colors.h"
#include "Snake.h"


class Cell
{
public:
	 enum EType
	 {
		  Empty,
		  Symbol,
		  SnakeSegment
	 };
public:
	 Cell();
	 void Set(EType pType, Color pColor);
	 void SetEmpty(bool pForce = false)
	 {
		  if(pForce || type != Symbol)
				Set(Empty, Colors::White);
	 }
	 Color GetColor();
	 bool IsObstacle();
	 bool IsEmpty()
	 {
		  return type == Empty;
	 }
	 bool BelongsToSnake(Snake* pSnake);

private:
	 Color color;
	 EType type;

};
