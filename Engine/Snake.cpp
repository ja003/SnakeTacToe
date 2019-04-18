#include "Snake.h"

Snake::Snake(std::string pName, Color pColor)
{
	 name = pName;
	 color= pColor;
	 segmentCount = 1;	 
}

Color Snake::GetColor()
{
	 return color;
}

Location Snake::Move(EDirection pDirection)
{
	 lastMoveDirection = pDirection;
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
	 for(int i = 0; i < segmentCount; i++)
	 {
		  segments.push_back(pStartPosition);
	 }
}

std::vector<Location> Snake::Deactivate()
{
	 std::vector<Location> copy(segments);
	 segments.clear(); 
	 return copy;
}
