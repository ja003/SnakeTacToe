#include "Table.h"

bool Table::isSelected(int pX, int pY)
{
	 int indexX = get<0>(selectedCellIndex);
	 int indexY = get<1>(selectedCellIndex);

	 return indexX == pX && indexY == pY;
}

void Table::setSelectedCell(int pX, int pY)
{
	 selectedCellIndex = make_tuple(pX, pY);
}

tuple<int, int> Table::getEmptyCell()
{
	 for(int y = 0; y < width; y++)
	 {
		  for(int x = 0; x < height; x++)
		  {
				if(cells[x][y].IsEmpty())
				{
					 return make_tuple(x, y);
				}
		  }
		  cout << endl;
	 }

	 return tuple<int, int>();
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

Table::Table(int pWidth, int pHeight, Graphics& gfx)
	 :
	 gfx(gfx),
	 width(pWidth),
	 height(pHeight)
{

	 cells = new Cell*[pWidth];
	 for(int i = 0; i < pWidth; ++i)
		  cells[i] = new Cell[pHeight];
}

void Table::Set(char pSymbol)
{
	 int pX = get<0>(selectedCellIndex);
	 int pY = get<1>(selectedCellIndex);
	 cells[pX][pY].Set(pSymbol);
	 tuple<int, int> emptyIndex = getEmptyCell();
	 setSelectedCell(get<0>(emptyIndex), get<1>(emptyIndex));
}

void Table::MoveSelectedCell(EDirection pDirection)
{
	 int indexX = get<0>(selectedCellIndex);
	 int indexY = get<1>(selectedCellIndex);
	 //todo: check bounds

	 switch(pDirection)
	 {
	 case Up:
		  setSelectedCell(indexX, indexY - 1);
		  break;
	 case Right:
		  setSelectedCell(indexX + 1, indexY);
		  break;
	 case Down:
		  setSelectedCell(indexX, indexY + 1);
		  break;
	 case Left:
		  setSelectedCell(indexX - 1, indexY);
		  break;
	 default:
		  break;
	 }
}

void Table::Draw()
{
	 int indexX = get<0>(selectedCellIndex);
	 int indexY = get<1>(selectedCellIndex);

	 cout << indexX << "," << indexY << endl;
	 cout << "--------------" << endl;
	 for(int y = 0; y < width; y++)
	 {
		  for(int x = 0; x < height; x++)
		  {
				Color c = cells[x][y].GetColor();
				drawCell(x, y, c);

				/*if(isSelected(x, y))
				{
					 //cout << "*" << " ";
					 drawCell(x, y, Color(255,255,255));
				}
				else
				{
					 //cout << cells[x][y].GetSymbol() << " ";
					 drawCell(x,y, cells[x][y].GetColor());

				}*/
		  }
		  cout << endl;
	 }
	 cout << "--------------" << endl;
}
