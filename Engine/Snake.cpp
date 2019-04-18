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

Location Snake::Move(EDirection pDirection)
{
	 Location next = GetHead() += pDirection;
	 segments.insert(segments.begin(), next);
	 Location last = segments.back();
	 segments.pop_back();
	 return last;
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
