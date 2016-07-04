//StockAccount.h
#pragma once
#include <iostream>
#include <string>
#include "StockHolding.h"
#include "CStock.h"
using namespace std;

class CStockAccount
{
public:
	//default constructor to initialize the ID to “NoID” and the cash balance to 10,000
	CStockAccount(void);

	//parameterized constructor to initialize the ID and the cash balance to specific values
	CStockAccount(string, double);

	//destructor.  Should be empty.
	~CStockAccount(void){};

	//function to add a stock into the account.  Prompt the user for stock symbol and shares
	//void addStock();
	//function to add a stock into the account if the stock symbol and shares are already known
	void addStock(string, int);
	//function to add a stock holding into the account
	//void addStock(CStockHolding);

	//function to delete a stock from the account.  Prompt the user for stock symbol and shares
	//void deleteStock();
	//function to delete number of shares of a stock from the account
	void deleteStock(string, int);
	//function to delete a holding from the account
	//void deleteStock(CStockHolding);

	//function to list the information of the account (ID, holdings, cash balance)
	void list();

	//Hw 11
	//friend ostream& operator <<(ostream& os, const CStockAccount& stocklist);

	//function to list only holdings
	void stockaccount();

	//data member for the ID
	string m_ID;
	//data member for the cash balance
	double m_CashBalance;
	//data member for 10 stock holdings
	CStockHolding m_Holdings[10];

	int getm_StockCount();

private:
	//private function to find the index of the stock symbol in the array m_Holdings. 
	//Return -1 if not found.
	int searchSymbol(string);

	//private member to count how many kinds of stock held
	int m_StockCount;

};