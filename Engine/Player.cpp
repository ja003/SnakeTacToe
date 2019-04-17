#include "Player.h"


Player::Player(string pName, Color pColor)
{
	 name = pName;
	 //symbol = pSymbol;
	 color = pColor;
}

//char Player::GetSymbol()
//{
//	 return symbol;
//}

Color Player::GetColor()
{
	 return color;
}
