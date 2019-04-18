#include "Cell.h"


Cell::Cell()
	 :
	 color(Colors::White),
	 type(Empty)
{}

void Cell::Set(EType pType, Color pColor)
{
	 color = pColor;
	 type = pType;
}


Color Cell::GetColor()
{
	 return color;
}

bool Cell::IsObstacle()
{
	 return type == Snake || type == Symbol;
}
