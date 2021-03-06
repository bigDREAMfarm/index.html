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
const double sales_tax = .05;

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
void getData(ifstream&, menuItemType[], int );
void showMenu(menuItemType[], order[], int , int&, double&);
void printCheck(ofstream&, order[],const double, double, int);
void reorder(char&, string);

int main()

{
	ifstream infile;
	ofstream outfile;

	string inputFile;
	string outputFile;
	int quantity_purchased;
	double sub_total = 0;

	menuItemType menuList[num_items];
	order purchaseList[num_items];
	
	string in_filename = "Ch9_Ex4Data.txt";
	infile.open(in_filename.c_str());

	if (!infile)
	{
		cout << " Cannot open the input file."
			<< endl;
		return 1;
	}

	string out_filename = "Ch9_Receipt.txt";
	outfile.open(out_filename.c_str());
	

	outfile << fixed << showpoint << setprecision(2);

	getData(infile, menuList, num_items);
	showMenu(menuList, purchaseList, num_items, quantity_purchased, sub_total);
	printCheck(outfile, purchaseList, sales_tax, sub_total, quantity_purchased);

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
void getData(ifstream& infile, menuItemType menuList[], int listSize)
{
	for (int index = 0; index < listSize; index++)
	{
		infile >> menuList[index].menuItem;
		infile >> menuList[index].menuPrice;
	}
}
void showMenu(menuItemType menuList[], order purchaseList[], int listSize, int& quantity_purchased,double& sub_total)
{
	int item_purchased;
	cout << " Johnny's Restaurant Menu " << endl;
	for (int index = 0; index < listSize; index++)
	{
		cout <<index << setw(10) << menuList[index].menuItem << setw(10) << menuList[index].menuPrice << endl;
	}
	
	cout << " Please enter the number items that you wish to purchase" << endl;
	cin >> quantity_purchased;

	cout << " Please enter each item number separated by a space: " << endl;
	for (int index = 0; index < quantity_purchased; index++)
	{
		cin >> item_purchased;
		cout << menuList[item_purchased].menuItem;
		purchaseList[index].menuItem = menuList[item_purchased].menuItem;
		cout << purchaseList[index].menuItem;
		cout << menuList[item_purchased].menuPrice;
		purchaseList[index].menuPrice = menuList[item_purchased].menuPrice ;
		cout << purchaseList[index].menuPrice;
		
		sub_total = purchaseList[index].menuPrice + sub_total;
		cout << sub_total;
		system("pause");
	}	
}

void printCheck(ofstream& outfile,order purchaseList[], double sub_total, double sales_tax, int listSize)
{
	double tax_amount,amount_due;
	outfile << " ------------- Welcome to Johnny's Restaurant ---------------" << endl;
	outfile << endl;
	for (int index = 0; index < listSize; index++)
	{
		cout << purchaseList[index].menuItem;
			cout << purchaseList[index].menuPrice << endl;
		outfile << purchaseList[index].menuItem << setw(10) << purchaseList[index].menuPrice << endl;
		
		system("pause");
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
