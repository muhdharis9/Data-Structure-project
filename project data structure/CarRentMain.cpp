#include <iostream>
#include "Customer.h" 
#include <stdlib.h>
using namespace std;


int main()
{

	Customer cstmr;
	string search, customername, icnumber;
	int Del;
	int choice = 0;


	int day = 0;

	do
	{
		cout << "\n\n***** CAR RENTAL SYSTEM *****" << endl; //THIS IS THE MAIN MENU
		cout << endl;
		cout << "[1] ADD ORDER" << endl;
		cout << "[2] DISPLAY ORDERS" << endl;
		cout << "[3] SORT ORDERS" << endl;
		cout << "[4] SEARCH " << endl;
		cout << "[5] DELETE ORDER" << endl;
		cout << "[6] EXIT" << endl << endl;
		cout << "PLEASE KEY-IN YOUR CHOICE [1]-[6] : ";
		cin >> choice;


		if (choice == 1) { // IF USER CHOOSES 1, THIS WILL FUNCTION AS ADDING ORDER
			system("CLS");
			cstmr.getCustomerInfo();
			system("CLS");
			cstmr.identifyCar();
			cstmr.calcTotalfee();

		}
		else if (choice == 2) // IF USER CHOOSES 2, IT WILL DISPLAY ALL ORDERS
		{
			system("CLS");
			cstmr.displayAll();

		}
		else if (choice == 3) // IF USER CHOOSES 3, IT WILL SORT THE LIST OF ORDERS
		{
			system("CLS");
			cout << "***THIS LIST IS ALREADY SORTED BY NAME***" << endl;
			cstmr.insertionSort();
			cstmr.displayAll();


		}
		else if (choice == 4) // IF USER CHOOSES 4, IT WILL BRING TO SEARCH FUNCTIONS
		{
			system("CLS");
			cout << "***SEARCHING***" << endl;
			cout << "PLEASE CHOOSE WHICH SEARCH YOU WANT TO USE: " << endl;
			cout << endl;
			cout << "[1] SEARCH BY IC NUMBER (SENTINAL SEARCH)" << endl;
			cout << "[2] SEARCH BY FIRST NAME (BINARY SEARCH)" << endl; // THIS IS THE MENU FOR SEARCH FUNCTIONS
			cout << endl;
			cout << "YOUR CHOICE [1] - [2]: ";
			cin >> choice;
			if (choice == 1) { // IF USER CHOOSES 1 FROM THE SEARCH MENU, IT WILL USE SENTINEL SEARCH BY IC NUMBER
				int index;
				cout << "Please enter the ic number that you want to search : ";
				cin >> icnumber;
				if (cstmr.searchSentinel(icnumber, index) == true)
				{
					cstmr.getRecord(index);
				}
				else if (cstmr.searchSentinel(icnumber, index) == false)
				{
					cout << "NO SUCH USER WITH THE IC NUMBER!!!";
				}



			}
			else if (choice == 2) {// IF USER CHOOSES 2 FROM THE SEARCH MENU, IT WILL USE BINARY SEARCH BY IC CUTOMER'S FIRST NAME
				int index1;
				cstmr.insertionSort();
				cout << "Please enter the first name that you want to search : ";
				cin >> customername;
				if (cstmr.searchBinary(customername, index1) == true)
				{
					cstmr.getRecord(index1);
				}
				else if (cstmr.searchBinary(customername, index1) == false)
				{
					cout << "NO SUCH USER WITH THE FIRST NAME!!!";
				}
			}
		}
		else if (choice == 5)// IF USER CHOOSES 5, IT WILL DISPLAY THE CUSTOMERS LIST AND ASK'S WHICH ORDER THEY WANT TO DELETE
		{
			system("CLS");
			cstmr.displayAll();
			cout << " Please key-in the index number of the student you want to delete : ";
			cin >> Del;
			cstmr.DeleteCust(Del);
		}
		else if (choice == 6)
		{
			cout << "*****THANK YOU*****";
			exit(0);
		}

	} while (choice >= 1 && choice <= 5);
}