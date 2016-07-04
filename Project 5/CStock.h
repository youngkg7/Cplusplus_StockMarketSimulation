//StockAccount.h
#pragma once
#include <iostream>
#include <string>
#include "StockAccount.h"


using namespace std;

class CStock
{
public:
	//default constructor to initialize the ID to “NoID” and the cash balance to 10,000
	CStock(void);

	//parameterized constructor to initialize the company, symbol and the price to specific values
	CStock(string, string, double);

	//destructor.  Should be empty.
	~CStock(void){};


	void output();
	void input();


	//data member for the company name
	string m_company;
	//data member for symbol 
	string m_symbol;

	//data member for the price of stock
	double m_price;

};