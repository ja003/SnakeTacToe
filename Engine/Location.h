#pragma once

#include "EDirection.h"
#include "Math.h"

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
	 //!!!UP = y-1, DOWN = y+1!!!
	 //LEFT = x-1, RIGHT = x+1
	 Location operator + (const EDirection dir) const
	 {
		  switch(dir)
		  {
		  case None: return { x, y };
		  case Up: return { x, y - 1 };
		  case Right: return { x + 1, y };
		  case Down: return { x, y + 1 };
		  case Left: return { x - 1, y };

		  case UpRight: return { x + 1, y - 1 };
		  case DownRight: return { x + 1, y + 1 };
		  case DownLeft: return { x - 1, y + 1 };
		  case UpLeft: return { x - 1, y - 1 };

		  }
	 }
	 Location operator - (const EDirection dir) const
	 {
		  return Location{ x, y } + Math::GetOpposite(dir);
	 }

	 Location& operator += (const EDirection dir)
	 {
		  switch(dir)
		  {
		  case None:
		  case Up:
				y -= 1;
				break;
		  case Right:
				x += 1;
				break;
		  case Down:
				y += 1;
				break;
		  case Left:
				x -= 1;
				break;

		  case UpRight:
				x += 1;
				y -= 1;
				break;
		  case DownRight:
				x += 1;
				y += 1;
				break;
		  case DownLeft:
				x -= 1;
				y += 1;
				break;
		  case UpLeft:
				x -= 1;
				y -= 1;
				break;
		  }
		  return *this;

	 }
	 Location& operator -= (const EDirection dir)
	 {
		  //todo: figure this shit out
		  /*Location* l = this;
		  l += Math::GetOpposite(dir);
		  return l;
		  &(this) += Math::GetOpposite(dir);*/

		  switch(dir)
		  {
		  case None:
		  case Up:
				y += 1;
				break;
		  case Right:
				x -= 1;
				break;
		  case Down:
				y -= 1;
				break;
		  case Left:
				x += 1;
				break;

		  case UpRight:
				x -= 1;
				y += 1;
				break;
		  case DownRight:
				x -= 1;
				y -= 1;
				break;
		  case DownLeft:
				x += 1;
				y -= 1;
				break;
		  case UpLeft:
				x += 1;
				y += 1;
				break;
		  }
		  return *this;
		  //return { x,y };
	 }

	 int x;
	 int y;
};