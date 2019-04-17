#include "Cell.h"

void Cell::Set(Color pColor)
{
	 color = pColor;
	 isEmpty = false;
}

//char Cell::GetSymbol()
//{
//	 return symbol;
//}

Cell::Cell()
	 :
	 color(Colors::White),
	 isEmpty(true)
{}

Color Cell::GetColor()
{
	 return color;
}

bool Cell::IsEmpty()
{
	 return isEmpty;
}
