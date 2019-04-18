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

bool Table::isWithinBounds(int pX, int pY)
{
	 return pX >= 0 && pX < width && pY >= 0 && pY < height;
}

void Table::swapSnakes()
{
	 activeSnake->Deactivate();
	 activeSnake == activeSnake->GetOponent();
	 activeSnake->Activate(getEmptyCell());
}


void Table::MakeSymbol()
{
	 Location snakeHead = activeSnake->GetHead();
	 cells[snakeHead.x][snakeHead.y].Set(Cell::Snake, activeSnake->GetColor());
	 swapSnakes();
}


void Table::Draw()
{
	 for(int y = 0; y < width; y++)
	 {
		  for(int x = 0; x < height; x++)
		  {
				Cell cell = cells[x][y];
				Color col = cell.GetColor();
				drawCell(x, y, col);
		  }
	 }
}

void Table::Move()
{
	 activeSnake->Move(MoveDirection);
}

void Table::SetActiveSnake(Snake * pSnake)
{
	 activeSnake = pSnake;
}
