#pragma once
#include "EDirection.h"

class Math
{
public:
	 static bool AreOpposites(EDirection pDir1, EDirection pDir2)
	 {
		  return GetOpposite(pDir1) == pDir2;
	 }
	 static EDirection GetOpposite(EDirection pDir)
	 {
		  switch(pDir)
		  {
		  case Up:
				return Down;
		  case Right:
				return Left;
		  case Down:
				return Up;
		  case Left:
				return Right;

		  case UpRight:
				return DownLeft;
		  case DownLeft:
				return UpRight;
		  case UpLeft:
				return DownRight;
		  case DownRight:
				return UpLeft;
		  }
		  return None;
	 }
};