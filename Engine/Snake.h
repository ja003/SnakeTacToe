#pragma once
#include <string>
#include <vector>
#include "Colors.h"
#include "Location.h"
#include <tuple>

using namespace std;
class Snake
{
private:
	 string name;
	 Color color;
	 int segmentCount;
	 vector<Location> segments;
public:
	 Snake(string pName, Color pColor);
	 Color GetColor();
};

