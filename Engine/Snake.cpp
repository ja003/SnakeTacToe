#include "Snake.h"

Snake::Snake(std::string pName, Color pColor)
{
	 name = pName;
	 color= pColor;
	 segmentCount = 1;	 
	 segments.push_back(Location{0,0});
}

Color Snake::GetColor()
{
	 return color;
}

void Snake::Move(EDirection pDirection)
{
	 //check if next is collision -> die
	 //remove last segment
	 //add new segment as first	 
}

Location Snake::GetHead()
{
	 return segments[0];
}

void Snake::Activate(Location pStartPosition)
{
	 segments.push_back(pStartPosition);
}

void Snake::Deactivate()
{
	 segments.clear();
}
