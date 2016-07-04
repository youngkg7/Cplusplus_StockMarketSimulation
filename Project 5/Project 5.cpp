//Filename:P5.cpp
//Programmer: Young Kwon			                                             CSCI 123 Fall '14
//Due Date: 12/4/2014                                                         Instructor:  Timothy Mai
//Program Description: Project 5, Stock Market simulation
#include <iostream>
#include "StockAccount.h"
#include "CStock.h"
#include "Stockmarket.h"
using namespace std;


void main()
{
	int menuoption;


	CStockmarket marketObject;

	marketObject.stockinitializefunction();
		do
		{
			marketObject.updateprice();
			system("cls");
			cout << "Welcome to the Stock Market." << endl;
			cout << "1. List all stocks." << endl;
			cout << "2. List all accounts." << endl;//account ids
			cout << "3. Open an account." << endl;
			cout << "4. Close an account." << endl;
			cout << "5. List all of the stocks of an account." << endl;//doesnt ouput cash balance
			cout << "6. List all information of an account." << endl;// does
			cout << "7. Buy a stock for an account." << endl;
			cout << "8. Sell a stock for an account." << endl;
			cout << "9. Calculate the total value of an account" << endl;
			cout << "10. Quit" << endl << endl;

			cout << "Please enter a number from the menu" << endl;
			cin >> menuoption;

			system("cls");

			switch (menuoption)
			{
			case 1: marketObject.stocklistingfunction();
				break;
			case 2: marketObject.accountlist();
				break;
			case 3: marketObject.openaccount();
				break;
			case 4: marketObject.closeaccount();
				break;
			case 5: marketObject.stocksofaccount();
				break;
			case 6: marketObject.allofaccount();
				break;
			case 7: marketObject.stocklistingfunction();
				marketObject.buystock();
				break;
			case 8: marketObject.stocklistingfunction();
				marketObject.sellstock();
				break;
			case 9: marketObject.totalvalue();
			case 10: break;
			default: cout << "Invalid entry. Please try again." << endl;
				break;
			}
			system("pause");
		} while (menuoption != 10);
}