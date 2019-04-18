#pragma once
#include <string>
#include <vector>
#include "Colors.h"
#include "Location.h"
#include "EDirection.h"
#include <tuple>

class Snake
{
private:
	 std::string name;
	 Color color;
	 int segmentCount;
	 std::vector<Location> segments;
	 Snake* oponent;
public:
	 Snake(std::string pName, Color pColor);
	 Color GetColor();
	 void Move(EDirection pDirection);
	 Location GetHead();
	 void SetOponent(Snake* pOponent)
	 {
		  oponent = pOponent;
	 }
	 Snake* GetOponent()
	 {

		  return oponent;
	 }
	 void Activate(Location pStartPosition);
	 void Deactivate();
};

