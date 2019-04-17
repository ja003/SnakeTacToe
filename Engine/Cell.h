#pragma once
using namespace std;
#include "Colors.h"


class Cell
{
private:
	 Color color;
	 bool isEmpty;
	 bool isSelected;
	 //char symbol;
public:
	 Cell();
	 void Set(Color pColor);
	 Color GetColor();
	 //char GetSymbol();
	 bool IsEmpty();
	 void SetSelected(bool pSelected);
	 bool IsSelected()
	 {
		  return isSelected;
	 };
};
