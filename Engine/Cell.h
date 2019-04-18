#pragma once
#include "Colors.h"


class Cell
{
public:
	 enum EType
	 {
		  Empty,
		  Symbol,
		  Snake
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

private:
	 Color color;
	 EType type;

};
