#include "Table.h"
#include "Math.h"
#include <vector>

Table::Table(int pWidth, int pHeight, int pWinPointsCount, Graphics& gfx)
	 :
	 gfx(gfx),
	 width(pWidth),
	 height(pHeight),
	 winPointsCount(pWinPointsCount)
{

	 cells = new Cell*[pHeight];
	 for(int i = 0; i < pWidth; ++i)
		  cells[i] = new Cell[pWidth];
}

void Table::MakeSymbol()
{
	 Location snakeHead = activeSnake->GetHead();
	 cells[snakeHead.x][snakeHead.y].Set(Cell::Symbol, activeSnake->GetColor());
	 activeSnake->IncreaseSegmentCount();
	 if(CheckWin())
		  return;
	 SwapSnakes();
}

void Table::Draw()
{
	 std::vector<Cell*> nonEmptyCells;
	 for(int y = 0; y < width; y++)
	 {
		  for(int x = 0; x < height; x++)
		  {
				Cell* cell = &cells[x][y];
				if(!cell->IsEmpty())
					 nonEmptyCells.push_back(cell);

				Color col = cell->GetColor();
				DrawCell(x, y, col);
		  }
	 }
	 if(nonEmptyCells.size() > 1)
	 {
		  int count = nonEmptyCells.size();
	 }
}

void Table::Move()
{
	 if(gameEnded)
		  return;

	 Location locOldTail = activeSnake->Move(moveDirection);
	 Cell* oldSnakeTail = GetCell(locOldTail);
	 oldSnakeTail->SetEmpty();

	 //check bounds
	 Location locHead = activeSnake->GetHead();
	 if(!IsWithinBounds(locHead))
	 {
		  SwapSnakes();
		  return;
	 }
	 //check collision
	 Cell* newSnakeHead = GetCell(locHead);
	 if(newSnakeHead->IsObstacle())
	 {
		  SwapSnakes();
		  return;
	 }
	 newSnakeHead->Set(Cell::SnakeSegment, activeSnake->GetColor());

	 int necc = GetNonEmptyCellCount();
	 int sc = activeSnake->GetSegmentCount();
	 if(necc > sc)
	 {
		  int c = 0;
	 }
}

void Table::SetActiveSnake(Snake * pSnake)
{
	 activeSnake = pSnake;
	 activeSnake->Activate(GetEmptyCell());
	 //set head visible in next frame
	 GetCell(activeSnake->GetHead())->Set(Cell::SnakeSegment, activeSnake->GetColor());

	 SetGoodDirection();
}

//Dont set direction opposite to the last one that snake made
void Table::SetMoveDirection(EDirection pDirection)
{
	 if(!Math::AreOpposites(activeSnake->GetLastMoveDirection(), pDirection))
		  moveDirection = pDirection;
}

//PRIVATE

//Check if there is enough same symbols connected to the last added symbol (activeSneak's head)
//in one direction.
//Has to be called right after symbol is added and snakes hasnt been swapped yet.
bool Table::CheckWin()
{
	 if(CheckWinInDirection(UpRight) || CheckWinInDirection(Right) ||
		  CheckWinInDirection(DownRight) || CheckWinInDirection(Down))
		  return true;

	 return false;
}

bool Table::CheckWinInDirection(EDirection pDirection)
{
	 Location head = activeSnake->GetHead();
	 int points = GetPointsInDirection(head, pDirection);
	 if(points >= winPointsCount)
	 {
		  Win();
		  return true;
	 }
	 return false;
}

//Counts number of cells in given and opposite direction from
//given starting cell belonging to active snake.
//Opposite direction os called recursively => pRecursionFlag = true
int Table::GetPointsInDirection(Location pStart, EDirection pDirection, bool pRecursionFlag)
{
	 int points = 0;
	 Location tmpLoc = pStart;
	 Cell* tmpCell = GetCell(tmpLoc);
	 while(tmpCell != nullptr && tmpCell->BelongsToSnake(activeSnake))
	 {
		  points++;

		  tmpLoc += pDirection;
		  tmpCell = GetCell(tmpLoc);
	 }

	 //dont count the starting cell twice (-1)
	 return points + (pRecursionFlag ? -1 : GetPointsInDirection(pStart, Math::GetOpposite(pDirection), true));
}

//Set MoveDirection so the next cell is empty.
//start with current MoveDirection value
void Table::SetGoodDirection()
{
	 Location headLoc = activeSnake->GetHead();

	 EDirection dir;
	 for(int i = 0; i < 4; i++)
	 {
		  //WARNING: this solution depends on static order of EDirection elements:
		  //- None, Up, Right, Down, Left, ...
		  //If the order is changed, behaviour will be different

		  //iterate though 4 directions (not 8!), skip None (+1), start with current (-1)
		  dir = EDirection((int(moveDirection) + i - 1) % 4 + 1);
		  Cell* cellInDir = GetCell(headLoc + dir);
		  if(cellInDir != nullptr && cellInDir->IsEmpty())
		  {
				moveDirection = dir;
				return;
		  }
	 }
	 //no good direction found...too bad, MoveDirection remains the same
}

Location Table::GetEmptyCell()
{
	 for(int y = 0; y < width; y++)
	 {
		  for(int x = 0; x < height; x++)
		  {
				if(cells[x][y].IsEmpty())
				{
					 return Location{ x, y };
				}
		  }
	 }

	 //todo: game end!
	 return Location{ 0,0 };
}

void Table::DrawCell(int pX, int pY, Color pColor)
{

	 //WTF..how to debug???
	 /*string msg = "";
	 msg += "[";
	 msg += pX;
	 msg += ",";
	 msg += pY;
	 msg += "] = ";
	 msg += pColor.GetR();*/
	 //OutputDebugStringA(L"" + msg);

	 //pColor = Colors::Cyan;
	 const int padding = 5;
	 gfx.DrawRectDim(pX * (CELL_WIDTH + padding), pY * (CELL_WIDTH + padding), CELL_WIDTH, CELL_WIDTH, pColor);
}

bool Table::IsWithinBounds(Location pLocation)
{
	 return pLocation.x >= 0 && pLocation.x < width && pLocation.y >= 0 && pLocation.y < height;
}

void Table::SwapSnakes()
{
	 std::vector<Location> snakeSegments = activeSnake->Deactivate();
	 for(auto s : snakeSegments)
	 {
		  if(IsWithinBounds(s)) //if snake went outside of borders, its head is OOB -> no need to set empty
				GetCell(s)->SetEmpty();
	 }

	 SetActiveSnake(activeSnake->GetOponent());
}


