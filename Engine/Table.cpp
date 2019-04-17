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

	 moveSelectedCellToEmpty();
}

bool Table::isSelected(int pX, int pY)
{
	 int indexX = get<0>(selectedCellIndex);
	 int indexY = get<1>(selectedCellIndex);

	 return indexX == pX && indexY == pY;
}

bool Table::setSelectedCell(int pX, int pY)
{
	 if(!isWithinBounds(pX, pY))
	 {
		  return false; //selection not set
	 }
	 selectedCellIndex = make_tuple(pX, pY);
	 cells[pX][pY].SetSelected(true);
	 return true;
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

bool Table::isWithinBounds(int pX, int pY)
{
	 return pX >= 0 && pX < width && pY >= 0 && pY < height;
}

void Table::moveSelectedCellToEmpty()
{
	 tuple<int, int> emptyIndex = getEmptyCell();
	 setSelectedCell(get<0>(emptyIndex), get<1>(emptyIndex));
}



void Table::Set(Color pColor)
{
	 int pX = get<0>(selectedCellIndex);
	 int pY = get<1>(selectedCellIndex);
	 cells[pX][pY].Set(pColor);
	 moveSelectedCellToEmpty();	 
}

void Table::MoveSelectedCell(EDirection pDirection)
{
	 int indexX = get<0>(selectedCellIndex);
	 int indexY = get<1>(selectedCellIndex);

	 bool selectionChanged = false;
	 switch(pDirection)
	 {
	 case Up:
		  selectionChanged = setSelectedCell(indexX, indexY - 1);
		  break;
	 case Right:
		  selectionChanged = setSelectedCell(indexX + 1, indexY);
		  break;
	 case Down:
		  selectionChanged = setSelectedCell(indexX, indexY + 1);
		  break;
	 case Left:
		  selectionChanged = setSelectedCell(indexX - 1, indexY);
		  break;
	 default:
		  break;
	 }

	/* Cell* c0 = cells[indexX, indexY];
	 Cell* c_u = cells[indexX, indexY - 1];
	 Cell* c_r = cells[indexX + 1, indexY];
	 Cell* c_d = cells[indexX, indexY + 1];
	 Cell* c_l = cells[indexX - 1, indexY];*/

	 //deselect
	 if(selectionChanged)
		  cells[indexX][indexY].SetSelected(false);
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
				Cell cell = cells[x][y];
				//Cell cell = cells[x][y];
				if(cell.IsSelected())
				{
					 int i = 0;
				}
				Color col = cell.GetColor();
				drawCell(x, y, col);
				//drawCell(x, y, cells[x][y].GetColor());

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
