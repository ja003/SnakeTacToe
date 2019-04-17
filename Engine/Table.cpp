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
				if(!cells[x][y].IsSet())
				{
					 return make_tuple(x, y);
				}
		  }
		  cout << endl;
	 }

	 return tuple<int, int>();
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
				if(isSelected(x, y))
				{
					 cout << "*" << " ";
				}
				else
				{
					 cout << cells[x][y].GetSymbol() << " ";
				}
		  }
		  cout << endl;
	 }
	 cout << "--------------" << endl;
}
