#include "Stockmarket.h"
#include "CStock.h"
#include <time.h>
#include <iostream>
#include <iomanip>


CStockmarket::CStockmarket()
{
	TotalNumOfAccounts = 0;
}


CStockmarket::~CStockmarket()
{
}

void CStockmarket::updateprice()
{
	srand((unsigned)time(NULL));
	int randomNumber = rand();			// generate a random number
	int  i = (randomNumber % 201);		// get a number between 0 - 200
	double percent = i / 100.0;			// get percentage

	if ((randomNumber % 2) != 0)		
		percent = -percent;				


	double newprice;

	for (int i = 0; i < 15; i++)
	{
		newprice = stocklist[i].m_price;

		if (percent < 0)
		{
			newprice -= ((percent * -1/100) * newprice);
			stocklist[i].m_price = newprice;
		}
		else
		{
			newprice += ((percent* 1/100) * newprice);
			stocklist[i].m_price = newprice;
		}

	}

}

void CStockmarket::buystock()
{

	CStockAccount temp;
	string stockSym;
	int numSharesBought;

	cout << "Please enter an account ID: ";
	cin >> temp.m_ID;

	int acctindex = searchID(temp.m_ID);

	if (acctindex == -1)
	{
		cout << "The account does not exist" << endl;
		return;
	}

	//Get name of stock
	cout << "Please enter the stock symbol of the company to purchase: ";
	cin >> stockSym;

	int stockindex = searchStock(stockSym);

	if (stockindex == -1)
	{
		cout << "The stock doesn't exist" << endl;
		return;
	}

	//Get number of shares to sell
	cout << "How many shares do you want to buy: ";
	cin >> numSharesBought;



	if (stocklist[stockindex].m_price*numSharesBought > m_accounthold[acctindex].m_CashBalance)
	{
		cout << "You do not have enough cash to purchase." << endl;
		return;
	}  


	if (TotalNumOfAccounts > 0 && acctindex > -1 && stockindex > -1)
	{
			m_accounthold[acctindex].m_CashBalance -= stocklist[stockindex].m_price * numSharesBought;
			m_accounthold[acctindex].addStock(stockSym, numSharesBought);
	}	
}

void CStockmarket::sellstock()
{
	CStockAccount temp;
	string stockSym;
	int numSharesSold;

	cout << "Please enter an account ID: ";
	cin >> temp.m_ID;

	int acctindex = searchID(temp.m_ID);

	if (acctindex == -1)
	{
		cout << "The account does not exist" << endl;
		return;
	}

	//Get name of stock
	cout << "Please enter the stock symbol of the company to sell: ";
	cin >> stockSym;

	int stockindex = searchStock(stockSym);

	if (stockindex == -1)
	{
		cout << "The stock doesn't exist" << endl;
		return;
	}

	//Get number of shares to sell
	cout << "How many shares do you want to sell: ";
	cin >> numSharesSold;

	int holdindex = searchSymbol(stockSym, acctindex);

	if (TotalNumOfAccounts > 0 && acctindex > -1 && stockindex > -1)
	{
		if (m_accounthold[acctindex].m_Holdings[holdindex].getNumOfShares() >= numSharesSold && m_accounthold[acctindex].getm_StockCount() != 0)
		{
			m_accounthold[acctindex].m_CashBalance += stocklist[stockindex].m_price * numSharesSold;
			m_accounthold[acctindex].deleteStock(stockSym, numSharesSold);
		}
		else
		{
			cout << "Sorry! The account doesn't hold enough shares." << endl;
			return;
		}
	}

}

void CStockmarket::accountlist()
{
	
	if (TotalNumOfAccounts > 0)
	{
		for (int i = 0; i < TotalNumOfAccounts; i++)
		{
			m_accounthold[i].list();
		}
	}

	else
		cout << "There are no accounts." << endl;
}
void CStockmarket::stocksofaccount()
{
	CStockAccount temp;

	cout << "Please enter an account ID: ";
	cin >> temp.m_ID;

	int index = searchID(temp.m_ID);

	if (index == -1)
	{
		cout << "The account does not exist" << endl;
		return;
	}


	if (TotalNumOfAccounts > 0 && index > -1)
			m_accounthold[index].stockaccount();
	else
		cout << "There are no accounts." << endl;
}

void CStockmarket::allofaccount()
{
	CStockAccount temp;

	cout << "Please enter an account ID: ";
	cin >> temp.m_ID;

	int index = searchID(temp.m_ID);

	if (index == -1)
	{
		cout << "The account does not exist" << endl;
		return;
	}


	if (TotalNumOfAccounts > 0 && index > -1)
		m_accounthold[index].list();
	else
		cout << "There are no accounts." << endl;
}

void CStockmarket::stocklistingfunction()
{
	
	// format for two numbers after decimal
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	for (int i = 0; i < 15; i++)
	{
		cout << stocklist[i];
	}
}

ostream& operator <<(ostream& os, CStock& stocklist)
{


		if (stocklist.m_company.length() < 8)
		{
			os << stocklist.m_company << "\t\t"
				<< stocklist.m_symbol << "\t"
				<< stocklist.m_price << endl;
		}
		else
		{
			os << stocklist.m_company << "\t"
				<< stocklist.m_symbol << "\t"
				<< stocklist.m_price << endl;
		}
	return os;
}

void CStockmarket::openaccount()
{

	do
	{
		cout << "Please enter an ID: ";
		cin >> m_accounthold[TotalNumOfAccounts].m_ID;

		if (searchID(m_accounthold[TotalNumOfAccounts].m_ID) > -1)
			cout << "Account already exists. Please try again." << endl;

	} while (searchID(m_accounthold[TotalNumOfAccounts].m_ID) > -1);

	do
	{
		cout << "Please enter a cash balance: $";
		cin >> m_accounthold[TotalNumOfAccounts].m_CashBalance;

		if (m_accounthold[TotalNumOfAccounts].m_CashBalance < 0)
			cout << "No negative cash balances allowed. Please try again." << endl;

	} while (m_accounthold[TotalNumOfAccounts].m_CashBalance < 0);

	TotalNumOfAccounts++;
	cout << "Account created successfully!" << endl;

}

int CStockmarket::searchID(string id)
{
	int index = -1;
	int i = 0;

	while (i < TotalNumOfAccounts)
	{

		if (m_accounthold[i].m_ID == id)
		{
			index = i;
		}

		i++;
	}

	return index;
}

int CStockmarket::searchStock(string sym)
{
	int index = -1;
	int i = 0;

	//check if stock exists in the market
	for (int i = 0; i < 15; ++i)
	{
		if (stocklist[i].m_symbol == sym)
		{
			index = i;
		}
	}

	return index;
}

int CStockmarket::searchSymbol(string s, int acctindex)
{
	int index = -1;
	int i = 0;

	while (i < 10)
	{

		if (m_accounthold[acctindex].m_Holdings[i].m_Symbol == s)
		{
			index = i;
		}

		i++;
	}

	return index;
}

void CStockmarket::closeaccount()
{
	CStockAccount temp;
	char confirmoption;

		cout << "Please enter an account ID you would like to close: ";
		cin >> temp.m_ID;

		//search for ID
		int index = searchID(temp.m_ID);

		if (index == -1)
		{
			cout << "Sorry, the account " << temp.m_ID << " does not exist." << endl;
			return;
		}

		do
		{
			cout << "Are you sure you want to close the account?" << endl;
			cin >> confirmoption;
		} while (confirmoption != 'n' && confirmoption != 'N' && confirmoption != 'y' && confirmoption != 'Y' );
		
		if (confirmoption == 'n' || confirmoption == 'N')
		{
			return;
		}

		if (index > -1)//
		{
			m_accounthold[index].m_ID = "NoID";
			m_accounthold[index].m_CashBalance = 10000;

			for (int i = index; i < TotalNumOfAccounts; i++)
			{
				if (index < 9)
				{
					m_accounthold[i].m_ID = m_accounthold[i + 1].m_ID;
					m_accounthold[i].m_CashBalance = m_accounthold[i + 1].m_CashBalance;
					m_accounthold[i] = m_accounthold[i + 1];
				}
				else if (index == 9)
				{
					m_accounthold[index].m_ID = "NoID";
					m_accounthold[index].m_CashBalance = 10000;
				}

			}
			TotalNumOfAccounts--;
			cout << "The account " << temp.m_ID << " has been successfully closed" << endl;
		}
}

void CStockmarket::totalvalue()
{
	CStockAccount temp;
	cout << "Please enter an account ID: ";
	cin >> temp.m_ID;

	int acctindex = searchID(temp.m_ID);

	if (acctindex == -1)
	{
		cout << "The account does not exist" << endl;
		return;
	}

	cout << "Account ID: " << m_accounthold[acctindex].m_ID << endl;
	cout << "Cash Balance: " << m_accounthold[acctindex].m_CashBalance << endl;

	double totalofaccount = m_accounthold[acctindex].m_CashBalance;
		cout << "The list of stocks: " << endl;
		int i = 0;
		while (i < m_accounthold[acctindex].getm_StockCount())
		{
			int stockindex = searchStock(m_accounthold[acctindex].m_Holdings[i].m_Symbol);
			cout.setf(ios::left);
			cout << "[ " << setw(4) << m_accounthold[acctindex].m_Holdings[i].m_Symbol << " ] "
				<< setw(5) << m_accounthold[acctindex].m_Holdings[i].getNumOfShares() << "\t" << "Value: ";
				cout.unsetf(ios::left);
			cout << setw(8) << m_accounthold[acctindex].m_Holdings[i].getNumOfShares() * stocklist[stockindex].m_price << endl;
			totalofaccount = totalofaccount + (m_accounthold[acctindex].m_Holdings[i].getNumOfShares() * stocklist[stockindex].m_price);
			i++;
		}

		cout << "Total account value: $" << totalofaccount;
		cout << endl;

}

void CStockmarket::stockinitializefunction()
{
	stocklist[0] = CStock("Apple", "AAPL", 450.00);
	stocklist[1] = CStock("AT&T", "T", 34.29);
	stocklist[2] = CStock("BankOfAmerica", "BAC", 17.75);
	stocklist[3] = CStock("Boeing", "BA", 75.50);
	stocklist[4] = CStock("Ford", "F", 14.15);
	stocklist[5] = CStock("GenericElectric", "GE", 26.05);
	stocklist[6] = CStock("Intel", "INTC", 22.30);
	stocklist[7] = CStock("MicroSoft", "MSFT", 45.15);
	stocklist[8] = CStock("Rambus", "RMBS", 5.55);
	stocklist[9] = CStock("PowerShares", "QQQ", 105.30);
	stocklist[10] = CStock("Sirius", "SIRI", 3.15);
	stocklist[11] = CStock("SeaDrill", "SDRL", 13.38);
	stocklist[12] = CStock("Skyworks", "SWKS", 25.35);
	stocklist[13] = CStock("ValeInc", "VALE", 8.33);
	stocklist[14] = CStock("Xilinix", "XLNX", 36.80);
}