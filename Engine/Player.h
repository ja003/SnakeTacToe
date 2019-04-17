#pragma once
#include <string>
#include "Colors.h"

using namespace std;

class Player
{
private:
	 string name;
	 //char symbol;
	 Color color;
	 
public:
	 Player(string pName, Color pColor);
	 //char GetSymbol();
	 Color GetColor();
};