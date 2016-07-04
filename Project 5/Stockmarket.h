#pragma once
#include "CStock.h"
#include "StockAccount.h"
using namespace std;

class CStockmarket
{
public:
	CStockmarket();
	~CStockmarket();
	
	void stockinitializefunction();
	void accountlist();
	void stocklistingfunction();
	void openaccount();
	void closeaccount();
	void stocksofaccount();
	void allofaccount();
	void buystock();
	void sellstock();
	void updateprice();
	void totalvalue();//bonus

	friend ostream& operator <<(ostream& os, CStock& stocklist);


	CStockAccount m_accounthold[10];
	CStock stocklist[15];

private:
	int searchID(string id);
	int searchStock(string sym);
	int searchSymbol(string s, int a);
	int TotalNumOfAccounts;
};

