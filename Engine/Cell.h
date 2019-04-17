#pragma once
using namespace std;


class Cell
{
private:
	 char symbol;
public:
	 void Set(char pSymbol);
	 char GetSymbol();
	 Cell();
	 bool IsSet();
};
