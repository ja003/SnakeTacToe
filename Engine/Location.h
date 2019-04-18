#pragma once

#include "EDirection.h"

class Location
{
public:
	 void Add(const Location& val)
	 {
		  x += val.x;
		  y += val.y;
	 }
	 bool operator==(const Location& rhs) const
	 {
		  return x == rhs.x && y == rhs.y;
	 }
	 bool operator!=(const Location& rhs) const
	 {
		  return !(*this == rhs);
	 }
	 Location operator-() const
	 {
		  return { -x,-y };
	 }
	 Location operator += (const EDirection dir)
	 {
		  switch(dir)
		  {
		  case None: return { x, y };
		  case Up: return { x, y - 1 };
		  case Right: return { x + 1, y };
		  case Down: return { x, y + 1 };
		  case Left: return { x - 1, y };
		  }
	 }

	 int x;
	 int y;
};