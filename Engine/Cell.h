#pragma once
using namespace std;
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

private:
	 Color color;
	 EType type;
public:
	 Cell();
	 void Set(EType pType, Color pColor);
	 Color GetColor();
	 bool IsObstacle();
};
