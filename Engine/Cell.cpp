#include "Cell.h"

void Cell::Set(char pSymbol)
{
	 symbol = pSymbol;
}

char Cell::GetSymbol()
{
	 return symbol;
}

Cell::Cell()
{
	 symbol = '_';
}

bool Cell::IsSet()
{
	 return symbol != '_';
}
