//StockHolding.h
#pragma once
#include <string>

using namespace std;

class CStockHolding
{
public:
	//default constructor to initialize the symbol to "N/A" and the number of shares to 0.
	CStockHolding(void);

	//parameterized constructor initialize the symbol and the number of shares to specific values.
	CStockHolding(string, int);

	//destructor.  Should be empty.
	~CStockHolding(void){};

	//mutator and an accessor for the private data member
	int getNumOfShares();
	void setNumOfShares(int n);

	string m_Symbol;

	//functions for inputs and outputs the holding information
	void input();
	void output();

private:
	int m_NumOfShares;
};