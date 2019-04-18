#include "Table.h"

Table::Table(int pWidth, int pHeight, Graphics& gfx)
	 :
	 gfx(gfx),
	 width(pWidth),
	 height(pHeight)
{

	 cells = new Cell*[pHeight];
	 for(int i = 0; i < pWidth; ++i)
		  cells[i] = new Cell[pWidth];
}


Location Table::getEmptyCell()
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

void Table::drawCell(int pX, int pY, Color pColor)
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

bool Table::isWithinBounds(Location pLocation)
{
	 return pLocation.x >= 0 && pLocation.x < width && pLocation.y >= 0 && pLocation.y < height;
}

void Table::swapSnakes()
{
	 std::vector<Location> snakeSegments = activeSnake->Deactivate();
	 for(auto s : snakeSegments)
	 {
		  if(isWithinBounds(s)) //if snake went outside of borders, its head is OOB -> no need to set empty
				getCell(s)->SetEmpty();
	 }

	 activeSnake = activeSnake->GetOponent();
	 activeSnake->Activate(getEmptyCell());
}


void Table::MakeSymbol()
{
	 Location snakeHead = activeSnake->GetHead();
	 cells[snakeHead.x][snakeHead.y].Set(Cell::Snake, activeSnake->GetColor());
	 activeSnake->IncreaseSegmentCount();
	 swapSnakes();
}


void Table::Draw()
{
	 for(int y = 0; y < width; y++)
	 {
		  for(int x = 0; x < height; x++)
		  {
				Cell* cell = &cells[x][y];
				Color col = cell->GetColor();
				drawCell(x, y, col);
		  }
	 }
}

void Table::Move()
{
	 Location locOldTail = activeSnake->Move(MoveDirection);
	 Cell* oldSnakeTail = getCell(locOldTail);
	 oldSnakeTail->SetEmpty();

	 Location locHead = activeSnake->GetHead();
	 Cell* newSnakeHead = getCell(locHead);
	 //first check bounds or OOR exception
	 if(!isWithinBounds(locHead) || newSnakeHead->IsObstacle())
	 {
		  swapSnakes();
		  return;
	 }
	 newSnakeHead->Set(Cell::Snake, activeSnake->GetColor());
}

void Table::SetActiveSnake(Snake * pSnake)
{
	 activeSnake = pSnake;
}
