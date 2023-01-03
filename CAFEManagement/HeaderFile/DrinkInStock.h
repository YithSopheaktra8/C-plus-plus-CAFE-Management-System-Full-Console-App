#ifndef DRINKINSTOCK____H__
#define DRINKINSTOCK____H__

#include "antheaderPlusPlus.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<windows.h>
using namespace std;


class DrinkInStock {

public:
	char barcode[30];
	char name[30];
	int qty;
	float price;

public:
	void inputData()
	{
		DrawRectangle(2,0,86,28,4);
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t  Input Drink Information" << endl;
		DrawRectangle(10,4,70,15,11);
		DrawRectangle(15,5,25,1,6);
		gotoxy(10,6);
		foreColor(13);
		cout << "\tInput Drink Barcode    :"; 
		DrawRectangle(42,5,33,1,6);
		gotoxy(43,6);
		foreColor(13);
		cin.get(barcode,30); fflush(stdin); cin.clear();
		DrawRectangle(15,8,25,1,6);
		gotoxy(10,9);
		foreColor(13);
		cout << "\tInput Drink Name    :"; 
		DrawRectangle(42,8,33,1,6);
		gotoxy(43,9);
		foreColor(13);
		cin.get(name,30); fflush(stdin); cin.clear();
		DrawRectangle(15,11,25,1,6);
		gotoxy(10,12);
		foreColor(13);
		cout << "\tInput Drink QTY   :";
		DrawRectangle(42,11,33,1,6);
		gotoxy(43,12);
		foreColor(13);
		cin >> qty;	fflush(stdin); cin.clear();
		DrawRectangle(15,14,25,1,6);
		gotoxy(10,15);
		foreColor(13);
		cout << "\tInput Drink Price    :";
		DrawRectangle(42,14,33,1,6);
		gotoxy(43,15);
		foreColor(13);
		cin >> price; fflush(stdin); cin.clear();	
	}
public:
	void outputData()
	{
		foreColor(13);
		cout << fixed << setprecision(2);		
		cout << left << setw(13) << barcode << setw(25) << name << setw(10) << qty << setw(10) << price << endl;
	}
public:
	void header()
	{
		DrawRectangle(2,0,86,28,4);
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t    Drink Information" << endl;		
//		DrawRectangle(10,4,70,20,11);
		foreColor(7);
		gotoxy(15,5);
		cout << left << setw(13) << "BARCODE" << setw(25) << "NAME" << setw(10) << "QTY" << setw(10) << "PRICE" << endl;

	}
public:
	void footer()
	{
		DrawRectangle(10,26,70,1,15);
		gotoxy(10,27);
		cout << "\t\t\t  ====>|Thank You|<====" << endl;
	}
public:
	void editData()
	{
		DrawRectangle(2,0,86,28,4);
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t  Input Drink Information" << endl;
		DrawRectangle(10,4,70,15,11);
		DrawRectangle(15,5,25,1,6);
		gotoxy(10,6);
		foreColor(13);
		cout << "\tInput Drink Barcode    :"; 
		DrawRectangle(42,5,33,1,6);
		gotoxy(43,6);
		foreColor(13);
		cin.get(barcode,30); fflush(stdin); cin.clear();
		DrawRectangle(15,8,25,1,6);
		gotoxy(10,9);
		foreColor(13);
		cout << "\tInput Drink Name    :"; 
		DrawRectangle(42,8,33,1,6);
		gotoxy(43,9);
		foreColor(13);
		cin.get(name,30); fflush(stdin); cin.clear();
		DrawRectangle(15,11,25,1,6);
		gotoxy(10,12);
		foreColor(13);
		cout << "\tInput Drink QTY   :";
		DrawRectangle(42,11,33,1,6);
		gotoxy(43,12);
		foreColor(13);
		cin >> qty;	fflush(stdin); cin.clear();
		DrawRectangle(15,14,25,1,6);
		gotoxy(10,15);
		foreColor(13);
		cout << "\tInput Drink Price    :";
		DrawRectangle(42,14,33,1,6);
		gotoxy(43,15);
		foreColor(13);
		cin >> price; fflush(stdin); cin.clear();
	}

};

#endif
