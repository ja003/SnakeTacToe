#include "Cell.h"


Cell::Cell()
	 :
	 color(Colors::White),
	 isEmpty(true),
	 isSelected(false)
{}

void Cell::Set(Color pColor)
{
	 color = pColor;
	 isEmpty = false;
	 SetSelected(false);
}


Color Cell::GetColor()
{
	 return isSelected ? Colors::Cyan : color;
}

bool Cell::IsEmpty()
{
	 return isEmpty;
}

void Cell::SetSelected(bool pSelected)
{
	 isSelected = pSelected;
}
