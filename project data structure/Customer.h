
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <iomanip>
#include <string.h>


using namespace std;

const int axiaRent = 80;//TO GET AXIA RENT PRICE
const int bezzaRent = 120;//TO GET BEZZA RENT PRICE
const int alzaRent = 140;//TO GET ALZA RENT PRICE
const int starexRent = 200;//TO GET STAREX RENT PRICE
const int maxSize = 10; // TO SET THE ARRAY OF ORDERS

struct RentalList {

	string customername = " ";
	string customerLname = " ";
	string icnumber = " ";
	string carname = " ";
	string sortCust = " ";
	char choose = ' ';
	int rentalfee = 0;
	int day = 0;
};


class Customer
{

private:

	RentalList record[maxSize];
	int size;


public:

	Customer();
	~Customer();
	void getCustomerInfo();
	void calcTotalfee();
	void displayAll();
	void identifyCar();
	void DeleteCust(int);
	void noAdd(string, string, string, string, int, int);
	void insertionSort();
	void getRecord(int);
	bool searchSentinel(string, int&);
	bool searchBinary(string target, int&);

};
#endif CUSTOMER_H




