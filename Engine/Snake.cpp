#include "Snake.h"



Snake::Snake()
{}


Snake::~Snake()
{}

Snake::Snake(string pName, Color pColor)
{
	 name = pName;
	 color= pColor;
	 segmentCount = 1;	 
}

Color Snake::GetColor()
{
	 return color;
}
