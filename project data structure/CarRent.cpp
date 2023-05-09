#include <iostream>
#include<string>
#include "Customer.h"
#include <iomanip>
using namespace std;

Customer::Customer()
{
	size = 0;

}
Customer::~Customer() {}


//BY HARIS
void Customer::getCustomerInfo() // FUNCTION TO GET CUSTOMER DETAILS SUCH AS FIRST NAME, LAST NAME AND IC NUMBER
{
	cout << "*** CUSTOMER DETAILS FORM ***" << endl;
	cout << endl;
	cout << "Please insert your first name : ";
	cin >> record[size].customername;
	cin.ignore();
	cout << endl;

	cout << "Please insert your last name : ";
	cin >> record[size].customerLname;
	cin.ignore();
	cout << endl;


	cout << "Please enter your IC number : ";
	cin >> record[size].icnumber;
	cin.ignore();
	cout << endl;


}

//BY IZZAT
void Customer::identifyCar() // FUNCTION TO GET CUSTOMERS CHOICE ON WHICH CAR THEY DESIRE 
{
	cout << "*** CAR SELECTION ***" << endl;
	cout << endl << "Please select a car from the options below" << endl;
	cout << endl;
	cout << "Enter [A] for ---PERODUA AXIA---  (RM 80/PER  DAY) " << endl;
	cout << "Enter [B] for ---PERODUA BEZZA--- (RM 120/PER DAY) " << endl;
	cout << "Enter [C] for ---PERODUA ALZA---  (RM 140/PER DAY) " << endl;
	cout << "Enter [D] for ---HYUNDAI STAREX---(RM 200/PER DAY) " << endl;
	cout << endl;
	cout << "Choose a Car from the above options: ";
	cin >> record[size].choose;
	cout << endl;


	if (record[size].choose == 'A' || record[size].choose == 'a')
	{
		record[size].carname = "AXIA";
		cout << "You have choosed Perodua Axia!!" << endl;


	}
	if (record[size].choose == 'B' || record[size].choose == 'b')
	{
		record[size].carname = "BEZZA";
		cout << "You have choosed Perodua Bezza!!" << endl;

	}
	if (record[size].choose == 'C' || record[size].choose == 'c')
	{
		record[size].carname = "ALZA";
		cout << "You have choosed Perodua Alza!!" << endl;

	}
	if (record[size].choose == 'D' || record[size].choose == 'd')
	{
		record[size].carname = "STAREX";
		cout << "You have choosed Hyundai Starex!!" << endl;

	}

	while (record[size].choose != 'A' && record[size].choose != 'a' && record[size].choose != 'B' && record[size].choose != 'b' && record[size].choose != 'C' && record[size].choose != 'c' && record[size].choose != 'D' && record[size].choose != 'd')
	{
		cout << "INVALID CAR MODEL!!!. Please try again!" << endl;
		cout << "Choose a Car from the above options: ";
		cin >> record[size].choose;

		cout << endl;

	}



}


//BY IZZAT
void Customer::calcTotalfee() //FUNCTION TO GET THE CUSTOMERS CHOICE ON HOW MANY DAYS THEY WANT TO RENT THE CAR
{

	cout << "How many days do you want to rent: ";
	cin >> record[size].day;
	cout << "Calculating rent. Please wait......" << endl;
	if (record[size].choose == 'A' || record[size].choose == 'a')
	{
		record[size].rentalfee = (axiaRent * record[size].day);
		size++;
	}
	else
	{
		if (record[size].choose == 'B' || record[size].choose == 'b')
		{
			record[size].rentalfee = (bezzaRent * record[size].day);
			size++;
		}
		else
		{
			if (record[size].choose == 'C' || record[size].choose == 'c')
			{
				record[size].rentalfee = (alzaRent * record[size].day);
				size++;
			}
			else
			{
				if (record[size].choose == 'D' || record[size].choose == 'd')
				{
					record[size].rentalfee = (starexRent * record[size].day);
					size++;
				}
			}
		}
	}

	system("CLS");
}


//BY MALIK
void Customer::displayAll() // FUNTION TO DISPLAY THE ORDER LIST
{
	cout << "List of Customer: \n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(10) << "  No.  " << setw(5) << "|" << setw(28) << "Name" << setw(22) << "|" << setw(10) << "Car Name" << setw(10) << "|" << setw(14) << "Ic Number" << setw(5) << "|" << setw(10) << "Day" << setw(10) << "|" << setw(15) << "Rental Fee (RM)" << setw(10) << "|" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|" << setw(6) << i + 1 << setw(9) << "|" << setw(22) << record[i].customername << " " << record[i].customerLname << setw(18) << "|" << setw(10) << record[i].carname << setw(10) << "|" << setw(14) << record[i].icnumber << setw(5) << "|" << setw(10) << record[i].day << setw(10) << "|" << setw(15) << record[i].rentalfee << setw(10) << "|" << fixed << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

//BY AMMAR
void Customer::noAdd(string f, string l, string i, string n, int d, int r) // FUNCTION TO SET ON HOW MANY ORDERS THE SYSTEM CAN RECEIVE USING ARRAY 
{
	if (size == maxSize)
	{
		cout << "***fully booked***";
		return;
	}

	record[size].customername = f;
	record[size].customerLname = l;
	record[size].icnumber = i;
	record[size].carname = n;
	record[size].day = d;
	record[size].rentalfee = r;
	size++;

}

//BY AMMAR
void Customer::insertionSort() // FUNCTION TO SORT THE ORDER LIST USING FIRSTNAME
{
	RentalList temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (record[i].customername > record[j].customername)
			{
				temp = record[i];
				record[i] = record[j];
				record[j] = temp;
			}
		}
	}



}

//BY HARIS
bool Customer::searchSentinel(string target, int& loc) // FUNCTION FOR THE SENTINEL SEARCH FORMULA
{


	if (size == 0)
	{
		cout << "\n***Empty list***" << endl;
	}
	else
	{
		int index = 0;
		bool found = false;

		while (index < size)
		{
			if (record[index].icnumber != target)
				index++;

			else
			{
				found = true;
				loc = index;
				break;
			}
		}


		return found;
	}

}


//BY IZZAT
bool Customer::searchBinary(string target, int& loc)// FUNCTION FOR THE BINARY SEARCH FORMULA
{
	int begin = 0, end = size - 1, mid = 0;
	bool found = false;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (target > record[mid].customername)
		{
			begin = mid + 1;
		}
		else if (target < record[mid].customername)
		{
			end = mid - 1;
		}
		else {
			begin = end + 1;
			found = true;
			loc = mid;
		}
	}
	return found;
}


//BY MALIK
void Customer::getRecord(int index) // FUNCTION FOR DISPLAY THE ORDER FROM USING SEARCH FUNCTION
{
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(28) << "Name" << setw(22) << "|" << setw(10) << "Car Name" << setw(10) << "|" << setw(14) << "Ic Number" << setw(5) << "|" << setw(10) << "Day" << setw(10) << "|" << setw(15) << "Rental Fee (RM)" << setw(10) << "|" << endl;

	{
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|" << setw(22) << record[index].customername << " " << record[index].customerLname << setw(22) << "|" << setw(10) << record[index].carname << setw(10) << "|" << setw(14) << record[index].icnumber << setw(5) << "|" << setw(10) << record[index].day << setw(10) << "|" << setw(15) << record[index].rentalfee << setw(10) << "|" << fixed << endl;


	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}


//BY HARIS
void Customer::DeleteCust(int a)// FUNCTION FOR DELETING CUSTOMER FROM THE ORDER LIST
{

	int counter = 0;

	for (int x = 0; x < size; x++)
	{
		record[a - 1].customername = record[x].customername;
		record[a - 1].icnumber = record[x].icnumber;
		record[a - 1].carname = record[x].carname;
		record[a - 1].customerLname = record[x].customerLname;
		record[a - 1].day = record[x].day;
		record[a - 1].rentalfee = record[x].rentalfee;


	}
	cout << "Succesfully Deleted!" << endl;

	size--;

}