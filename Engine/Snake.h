#pragma once
#include <string>
#include <vector>
#include "Colors.h"
#include "Location.h"
#include "EDirection.h"
#include <tuple>

class Snake
{
public:
	 Snake(std::string pName, Color pColor);
	 Color GetColor();
	 Location Move(EDirection pDirection);
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
	 std::vector<Location> Deactivate();
	 void IncreaseSegmentCount()
	 {
		  segmentCount++;
	 }
private:
	 std::string name;
	 Color color;
	 int segmentCount;
	 std::vector<Location> segments;
	 Snake* oponent;

};

