#include <iostream>
#include "StockAccount.h"
#include <string>

using namespace std;

//Start of CStockAccount Implementation
CStockAccount::CStockAccount(void)
{
	m_ID = "NoID";
	m_CashBalance = 10000;
	m_StockCount = 0;
}

CStockAccount::CStockAccount(string i, double c)
{
	m_ID = i;
	m_CashBalance = c;
}

int CStockAccount::getm_StockCount()
{
	return m_StockCount;
}


void CStockAccount::addStock(string symbol, int newshares)
{
	//Search for symbol index
	int index = searchSymbol(symbol);
	

	if (index >= 0)//add stocks to existing index
	{
		int oldshares = m_Holdings[index].getNumOfShares();
		m_Holdings[index].setNumOfShares(oldshares + newshares);
		cout << "Transaction was successful!" << endl;
	}

	else if (m_StockCount < 10)//check for space for stocks 
	{
		m_Holdings[m_StockCount].m_Symbol = symbol;//set symbol
		m_Holdings[m_StockCount].setNumOfShares(newshares);//set the amount of shares
		m_StockCount++;
		cout << "Transaction was successful!" << endl;
	}

	else if (m_StockCount >= 10)
	{
		cout << "Sorry! Maximum number of stocks reached" << endl;
	}

}


void CStockAccount::deleteStock(string symbol, int newshares)
{

	if (m_StockCount <= 0)
	{
		cout << "There are no stocks held.\n";
		return;
	}

	//Search for Symbol index
	int index = searchSymbol(symbol);

	if (index == -1)
	{
		cout << "The account does not hold this stock" << endl;
		return;
	} 

	if (index >= 0)
	{
		int oldshares = m_Holdings[index].getNumOfShares();

		if (oldshares > newshares)
		{
			m_Holdings[index].setNumOfShares(oldshares - newshares);
			cout << "Transaction was successful!" << endl;
		}

		else if (oldshares == newshares)
		{
			for (index; index < m_StockCount; ++index)
			{
				if (index < 9)//fill hole in array.
				{
					m_Holdings[index].m_Symbol = m_Holdings[index + 1].m_Symbol;

					int newshares2 = m_Holdings[index + 1].getNumOfShares();
					m_Holdings[index].setNumOfShares(newshares2);
					cout << "Transaction was successful!" << endl;
				}

				//Since last item was moved to index 8, need to make 9 standard
				if (index == 9)
				{
					m_Holdings[index].m_Symbol = "N/A";
					m_Holdings[index].setNumOfShares(0);
					cout << "Transaction was successful!" << endl;
				}
			}
			--m_StockCount;
		}
	}
	else
	{
		cout << "The stock " << symbol << " is not in the list." << endl;
	}
}


void CStockAccount::list()
{
	cout << "Account ID: " << m_ID << endl;
	cout << "Cash Balance: " << m_CashBalance << endl;

	if (m_StockCount <= 0)
		cout << "There are no stocks held." << endl << endl;
	else
	{
		cout << "The list of stocks: " << endl;
		int i = 0;
		while (i < m_StockCount)
		{
			cout << "[ " << m_Holdings[i].m_Symbol << " ] "
				<< m_Holdings[i].getNumOfShares() << endl;  
			i++;
		}

		cout << endl;
	}
}
void CStockAccount::stockaccount()
{
	cout << "Account ID: " << m_ID << endl;

	if (m_StockCount <= 0)
		cout << "There are no stocks held." << endl << endl;
	else
	{
		cout << "The list of stocks: " << endl;
		int i = 0;
		while (i < m_StockCount)
		{
			cout << "[ " << m_Holdings[i].m_Symbol << " ] "
				<< m_Holdings[i].getNumOfShares() << endl;
			i++;
		}

		cout << endl;
	}
}

int CStockAccount::searchSymbol(string s)
{
	int index = -1;
	int i = 0;

	while (i < m_StockCount)
	{

		if (m_Holdings[i].m_Symbol == s)
		{
			index = i;
		}

		i++;
	}

	return index;
}

 
//End of CStockAccount Implementation


