
#include "HeaderFile\HidePassword.h"
#include "HeaderFile\DrinkFileIO.h"
#include "HeaderFile\DrinkInStock.h"
#include "HeaderFile\AllStaffFileIO.h"
#include "HeaderFile\AllStaff.h"

using namespace std;

void DrinkMenu();
void Login();
void AdminMenu();
void StaffMenu();


int main()
{
	Login();	
	
	getch(); return 0;
}

void AdminMenu()
{
	int opt;
	system("cls");
	DrawRectangle(2,0,86,28,4);
	DrawRectangle(10,1,70,1);
	gotoxy(10,2);
	cout << "\t\t\t   ADMIN MENU MANAGEMENT" << endl;
	gotoxy(10,5);
	DrawRectangle(10,4,70,23,11);
	DrawRectangle(25,5,40,1,6);
	foreColor(13);
	gotoxy(10,6);
	cout << "\t\t\t   [1] Drink Management";
	DrawRectangle(25,9,40,1,6);
	foreColor(13);
	gotoxy(10,10);
	cout << "\t\t\t   [2] Staff Management";
	DrawRectangle(25,13,40,1,6);
	foreColor(13);
	gotoxy(10,14);
	cout << "\t\t\t   [3] Exit Program";
	DrawRectangle(25,17,40,1,6);
	foreColor(13);
	gotoxy(10,17);
	cout <<"\n\t\t\t\t    Choose Option : "; cin >> opt ; fflush(stdin); cin.clear();
	switch(opt)
	{
		case 1: do{
				system("cls");
				DrinkMenu();		
		}while(1);
		break;
		case 2: do{
				system("cls");
				StaffMenu();
		}while(1);
		break;
		case 3: 
				gotoxy(10,60);
				exit(1);
		
		break;
	}
	
	
}

void DrinkMenu()
{
	int option;
	system("cls");
	DrawRectangle(2,0,86,28,4);
	DrawRectangle(10,1,70,1);
	gotoxy(10,2);
	cout <<"\t\t\t    Drink Management ";
	gotoxy(10,5);
	DrawRectangle(10,4,70,23,11);
	DrawRectangle(25,5,40,1,6);
	foreColor(13);
	gotoxy(10,6);
	cout <<"\t\t\t    [1] Insert Drink";
	DrawRectangle(25,8,40,1,6);
	foreColor(13);
	gotoxy(10,9);
	cout <<"\t\t\t    [2] View all Drink";
	DrawRectangle(25,11,40,1,6);
	foreColor(13);
	gotoxy(10,12);
	cout <<"\t\t\t    [3] Search Drink";
	DrawRectangle(25,14,40,1,6);
	foreColor(13);
	gotoxy(10,15);
	cout <<"\t\t\t    [4] Update Drink";
	DrawRectangle(25,17,40,1,6);
	foreColor(13);
	gotoxy(10,18);
	cout <<"\t\t\t    [5] Delete Drink";
	DrawRectangle(25,20,40,1,6);
	foreColor(13);
	gotoxy(10,21);
	cout <<"\t\t\t    [6] Back to MainMenu";
	DrawRectangle(25,23,40,1,6);
	foreColor(13);
	gotoxy(10,24);
	cout <<"\t\t\t    Choose Option : "; cin >> option ; fflush(stdin); cin.clear();
	
	switch(option)
	{
		case 1:
			{
				do
				{
					system("cls");
					InsertDrink();
					DrawRectangle(10,22,70,1,2);
					gotoxy(10,23);
					foreColor(2);
					cout << "                      Insert Drink Successfully";
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Insert] again  "; 
					
				}while(getch()!=27);
				DrinkMenu();
			}			
			break;
		case 2:
			{
				do
				{
					system("cls");
					ViewAllDrink();
					DrawRectangle(10,26,70,1,15);
					gotoxy(20,27);
					foreColor(2);
					cout << "\t\t  Press [ESC] to back MENU "; 
					
				}while(getch()!=27);
				DrinkMenu();
			}
			break;
		case 3:
			{
				do
				{
					system("cls");
					SearchDrink();
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Search] again  "; 
					
				}while(getch()!=27);
				DrinkMenu();
			}
			break;
		case 4:
			{
				do
				{
					system("cls");
					UpdateDrink();
					gotoxy(10,5);
					DrawRectangle(10,4,70,15,11);
					gotoxy(10,23);
					DrawRectangle(10,22,70,1,2);
					gotoxy(25,23);
					cout << "        Update was successfully!!!  ";
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Update] again  "; 
					
				}while(getch()!=27);
				DrinkMenu();
			}
			break;
		case 5:
			{
				do
				{
					system("cls");
					DeleteDrink();
					gotoxy(10,5);
					DrawRectangle(10,4,70,15,11);
					gotoxy(10,23);
					DrawRectangle(10,22,70,1,2);
					gotoxy(25,23);
					cout << "        Delete was successfully!!!  ";
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Update] again  "; 
					
				}while(getch()!=27);
				DrinkMenu();
			}
			break;
		case 6:
				AdminMenu();
				break;
	}
}

void StaffMenu()
{
	int option;
	system("cls");
	DrawRectangle(2,0,86,28,4);
	DrawRectangle(10,1,70,1);
	gotoxy(10,2);
	cout <<"\t\t\t    Staff Management ";
	gotoxy(10,5);
	DrawRectangle(10,4,70,23,11);
	DrawRectangle(25,5,40,1,6);
	foreColor(13);
	gotoxy(10,6);
	cout <<"\t\t\t    [1] Insert Staff";
	DrawRectangle(25,8,40,1,6);
	foreColor(13);
	gotoxy(10,9);
	cout <<"\t\t\t    [2] View all Staff";
	DrawRectangle(25,11,40,1,6);
	foreColor(13);
	gotoxy(10,12);
	cout <<"\t\t\t    [3] Search Staff";
	DrawRectangle(25,14,40,1,6);
	foreColor(13);
	gotoxy(10,15);
	cout <<"\t\t\t    [4] Update Staff";
	DrawRectangle(25,17,40,1,6);
	foreColor(13);
	gotoxy(10,18);
	cout <<"\t\t\t    [5] Delete Staff";
	DrawRectangle(25,20,40,1,6);
	foreColor(13);
	gotoxy(10,21);
	cout <<"\t\t\t    [6] Back to MainMenu";
	DrawRectangle(25,23,40,1,6);
	foreColor(13);
	gotoxy(10,24);
	cout <<"\t\t\t    Choose Option : "; cin >> option ; fflush(stdin); cin.clear();
	switch(option)
	{
		case 1:
			{
				do
				{
					system("cls");
					InsertStaff();
					DrawRectangle(10,22,70,1,2);
					gotoxy(10,23);
					foreColor(2);
					cout << "                      Insert Data Successfully";
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Insert] again  "; 
					
				}while(getch()!=27);
				StaffMenu();
			}			
			break;
		case 2:
			{
				do
				{
					system("cls");
					ViewAllStaff();
					DrawRectangle(10,26,70,1,15);
					gotoxy(20,27);
					foreColor(2);
					cout << "\t\t  Press [ESC] to back MENU "; 
					
				}while(getch()!=27);
				StaffMenu();
			}
			break;
		case 3:
			{
				do
				{
					system("cls");
					SearchStaff();
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Search] again  "; 
					
				}while(getch()!=27);
				StaffMenu();
			}
			break;
		case 4:
			{
				do
				{
					system("cls");
					UpdateStaff();
					gotoxy(10,5);
					DrawRectangle(10,4,70,15,11);
					gotoxy(10,23);
					DrawRectangle(10,22,70,1,2);
					gotoxy(25,23);
					cout << "        Update was successfully!!!  ";
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Update] again  "; 
					
				}while(getch()!=27);
				StaffMenu();
			}
			break;
		case 5:
			{
				do
				{
					system("cls");
					DeleteStaff();
					gotoxy(10,5);
					DrawRectangle(10,4,70,15,11);
					gotoxy(10,23);
					DrawRectangle(10,22,70,1,2);
					gotoxy(25,23);
					cout << "        Delete was successfully!!!  ";
					DrawRectangle(10,26,70,1,15);
					gotoxy(10,27);
					foreColor(2);
					cout << "        Press [ESC] to back MENU and any key to [Update] again  "; 
					
				}while(getch()!=27);
				StaffMenu();
			}
			break;
		case 6:
				AdminMenu();
				break;
	}
}

void Login()
{	
	while(true)
	{
		char username[25];
		char password[30];
		
	
		system("cls");
		DrawRectangle(2,0,86,28,4);
		DrawRectangle(15,5,60,1,6);
		gotoxy(28,6);
		cout << "WELCOME TO CAFE MANAGEMENT SYSTEM";
		DrawRectangle(15,8,60,1,2);
		gotoxy(23,9);
		cout << "Please Input Username and Password to login";
		DrawRectangle(20,11,18,1);
		gotoxy(22,12);
		cout << "Enter Username  "; 
		DrawRectangle(40,11,25,1);
		gotoxy(41,12);
		cin>>username; fflush(stdin);
		DrawRectangle(20,14,18,1);
		gotoxy(22,15);
		cout << "Enter Password  "; 
		DrawRectangle(40,14,25,1);
		gotoxy(41,15);
		hidePassword(password); 
			
		
		if( !strcmp(username, "admin") && !strcmp(password, "1234"))
		{
			
			DrawRectangle(30,19,25,1,2);
			gotoxy(33,20);
			foreColor(2);cout << "login Successfully" << endl;
			delay(1000);						
			AdminMenu();
		}
		else
		{	DrawRectangle(30,19,25,1,12);
			gotoxy(31,20);
			foreColor(12);cout << "Error: Invalid Password!" << endl; getch();
			
		}
					
	}
}

