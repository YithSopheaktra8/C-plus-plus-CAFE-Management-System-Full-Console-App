#ifndef ALLSTAFF____H__
#define ALLSTAFF____H__

#include "antheaderPlusPlus.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<windows.h>
using namespace std;

class Staff{
	public:
		char id[30];
		char name[30];
		char gender[10];
		int age;
		char position[30];
	public:
		void InputStaff()
		{
			DrawRectangle(2,0,86,28,4);
			DrawRectangle(10,1,70,1);
			gotoxy(10,2);
			cout << "\t\tInsert Staff Information" << endl;
			gotoxy(10,5);
			DrawRectangle(10,4,70,15,11);
			DrawRectangle(15,5,25,1,6);
			gotoxy(10,6);
			foreColor(13);
			cout << "\tInput Staff ID       : "; 
			DrawRectangle(42,5,33,1,6);
			gotoxy(43,6);
			foreColor(13);
			cin.get(id,30); fflush(stdin); cin.clear();
			DrawRectangle(15,8,25,1,6);
			gotoxy(10,9);
			foreColor(13);
			cout << "\tInput Staff Name     : "; 
			DrawRectangle(42,8,33,1,6);
			gotoxy(43,9);
			foreColor(13);
			cin.get(name,30); fflush(stdin); cin.clear();
			DrawRectangle(15,11,25,1,6);
			gotoxy(10,12);
			foreColor(13);
			cout << "\tInput Staff Gender   : "; 
			DrawRectangle(42,11,33,1,6);
			gotoxy(43,12);
			foreColor(13);
			cin.get(gender,10); fflush(stdin); cin.clear();
			DrawRectangle(15,14,25,1,6);
			gotoxy(10,15);
			foreColor(13);
			cout << "\tInput Staff Age      : "; 
			DrawRectangle(42,14,33,1,6);
			gotoxy(43,15);
			foreColor(13);
			cin >> age; fflush(stdin); cin.clear();
			DrawRectangle(15,17,25,1,6);
			gotoxy(10,18);
			foreColor(13);
			cout << "\tInput Staff Position : "; 
			DrawRectangle(42,17,33,1,6);
			gotoxy(43,18);
			foreColor(13);
			cin.get(position,30); fflush(stdin); cin.clear();
		}
		void ViewStaff()
		{
			foreColor(13);	
			cout << left << setw(13) << id << setw(18) << name << setw(10) << gender << setw(10) << age << setw(10) << position << endl;
		}
		void Header()
		{
			DrawRectangle(2,0,86,28,4);
			DrawRectangle(10,1,70,1);
			gotoxy(10,2);
			cout << "\t\t\t    Drink Information" << endl;		
			DrawRectangle(10,4,70,20,11);
			foreColor(7);
			gotoxy(15,5);
			cout << left << setw(13) << "ID" << setw(18) << "NAME" << setw(10) << "GENDER" << setw(10) << "AGE" << setw(10) << "POSITION" << endl;
		}
		void Footer()
		{
			DrawRectangle(10,26,70,1,15);
			gotoxy(10,27);
			cout << "\t\t\t  ====>|Thank You|<====" << endl;
		}
		void EditStaff()
		{
			DrawRectangle(2,0,86,28,4);
			DrawRectangle(10,1,70,1);
			gotoxy(10,2);
			cout << "\t\t\tInsert Staff Information" << endl;
			gotoxy(10,5);
			DrawRectangle(10,4,70,15,11);
			gotoxy(10,6);
			foreColor(13);
			cout << "\t\tInput New Staff ID       : "; cin.get(id,30); fflush(stdin); cin.clear();
			gotoxy(10,8);
			cout << "\t\tInput New Staff Name     : "; cin.get(name,30); fflush(stdin); cin.clear();
			gotoxy(10,10);
			cout << "\t\tInput New Staff Gender   : "; cin.get(gender,10); fflush(stdin); cin.clear();
			gotoxy(10,12);
			cout << "\t\tInput New Staff Age      : "; cin >> age; fflush(stdin); cin.clear();
			gotoxy(10,14);
			cout << "\t\tInput New Staff Position : "; cin.get(position,30); fflush(stdin); cin.clear();
		}
};

#endif
