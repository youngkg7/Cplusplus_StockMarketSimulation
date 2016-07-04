#include <iostream>
#include "CStock.h"
#include <string>

using namespace std;

//Start of CStockAccount Implementation
CStock::CStock(void)
{
	m_company = "N/A";
	m_price = 0;
	m_symbol = "N/A";
}

CStock::CStock(string c, string m, double p)
{
	m_company = c;
	m_symbol = m;
	m_price = p;
}

void CStock::output()
{
	cout << m_symbol << " [ " << m_company << " ] " << " $" << m_price;
}

void CStock::input()
{
	cout << "Please enter the symbol of the company: ";
	cin >> m_symbol;
	cout << "Please enter the company name of the stock: ";
	cin >> m_company;
	cout << "Please enter the price of the stock: ";
	cin >> m_price;

}