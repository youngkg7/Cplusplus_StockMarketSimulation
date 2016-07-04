#include <iostream>
#include "StockHolding.h"

using namespace std;

//Start of CStockHolding Implementation
CStockHolding::CStockHolding(void)
{
	m_Symbol = "N/A";
	m_NumOfShares = 0;
}

CStockHolding::CStockHolding(string s, int n)
{
	m_Symbol = s;
	m_NumOfShares = n;
}

void CStockHolding::input()
{
	cout << "Please enter the stock symbol: ";
	cin >> m_Symbol;
	cout << "Please enter number of shares: ";
	cin >> m_NumOfShares;
}

void CStockHolding::output()
{
	cout << "[ " << m_Symbol << " ] " << getNumOfShares() << endl;
}

int CStockHolding::getNumOfShares()
{
	return m_NumOfShares;
}

void CStockHolding::setNumOfShares(int n)
{
	m_NumOfShares = n;
}
//End of CStockHolding Implementation