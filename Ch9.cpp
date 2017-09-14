/*
Clark, Ryan
Unit 9 "Ch9_4_Program"
CSIS 223
Fall 2017
Complier VCE 2013

This program automates the breakfast billing system.
-shows the breakfast menu
-allow the cusotmer to select more than one item from the menu
-calculate and print the bill


*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int num_items = 8;
const double sales_tax = 1.05;

struct menuItemType
{
	string menuItem;
	double menuPrice;
};
struct order
{
	string menuItem;
	double menuPrice;
	double amountPurchased;
};



bool isValid();
void getData(ifstream& infile, menuItemType menuList[], int listSize);
void showMenu(menuItemType menuList[], order purchaseList[], int listSize, int& quantity_purchased, double& tot);
void printCheck(ofstream& outfile,menuItemType purchaseList[],double sales_tax, int listSize);
void reorder(char&, string);

int main()

{
	ifstream infile;
	ofstream outfile;

	string inputFile;
	string outputFile;
	int quantity_purchased;
	double sub_total;

	menuItemType menuList[num_items];
	order purchaseList[num_items];
	
	cout << "Enter the menu ID file name: ";
	cin >> inputFile;
	cout << endl;

	infile.open(Ch9_Ex4Data.txt);

	if (!infile)
	{
		cout << " Cannot open the input file."
			<< endl;
		return 1;
	}

	outfile.open(Ch9_Receipt.txt);
	outfile << fixed << showpoint << setprecision(2);

	getData(infile, menuList, num_items);
	showMenu(menuList, purchaseList, num_items, quantity_purchased, sub_total);
	printCheck(outfile, purchaseList, sub_total, sales_tax, quantity_purchased);

	
	infile.close();
	outfile.close();

	return 0;
	
}
bool isValid()
{//input validation for int
	if (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		system("cls");
		return false;
	}
	else
		return true;
}
void getData(ifstream& indata, menuItemType menuList[], int listSize)
{
	for (int index = 0; index < listSize; index++)
	{
		indata >> menuList[index].menuItem;
		indata >> menuList[index].menuPrice;
	}
}
void showMenu(menuItemType menuList[], order purchaseList[], int listSize, int& quantity_purchased,double& tot)
{
	int item_purchased;
	double total = 0;
	cout << " Johnny's Restaurant Menu " << endl;
	for (int index = 0; index < listSize; index++)
	{
		cout <<index << setw(10) << menuList[index].menuItem << setw(10) << menuList[index].menuPrice << endl;
	}
	
	cout << " Please enter the number items that you wish to purchase" << endl;
	cin >> quantity_purchased;

	cout << " Please enter each item number separated by a space: " << endl;
	for (int index = 0; index < num_items; index++)
	{
		cin >> item_purchased;
		menuList[item_purchased].menuItem = purchaseList[item_purchased].menuItem;
		menuList[item_purchased].menuPrice = purchaseList[item_purchased].menuPrice;
		total = menuList[item_purchased].menuPrice + total;
	}	
}

void printCheck(ofstream& outfile,menuItemType purchaseList[], double sub_total, double sales_tax, int listSize)
{
	int index;
	double tax_amount,amount_due;
	outfile << " ------------- Welcome to Johnny's Restaurant ---------------" << endl;
	outfile << endl;
	for (int index = 0; index < num_items; index++)
	{
		outfile << purchaseList[index].menuItem << setw(10) << purchaseList[index].menuPrice << endl;
	}
	tax_amount = sub_total * sales_tax;
	outfile << "Tax" << setw(10) << tax_amount << endl;
	amount_due = sub_total + tax_amount;
	outfile << "Total" << setw(10) << amount_due << endl;
}
void reorder(char &c1, string msg)
{ // handles input failure by clearing values and notifying user
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	c1 = NULL;
	cout << msg;
	system("pause");
	system("cls");
	
}
