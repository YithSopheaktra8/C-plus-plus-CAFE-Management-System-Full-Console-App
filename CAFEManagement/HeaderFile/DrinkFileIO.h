#ifndef FILEDRINKINSTOCK______H___
#define FILEDRINKINSTOCK______H___

#include<fstream>
#include "..\HeaderFile\DrinkInStock.h"

fstream file,file1;
DrinkInStock ds;

void OrderDrink()
{
	file.open("DrinkInformation.bin", ios::in | ios::binary);
	if(file.fail())
	{	
		DrawRectangle(2,0,86,28,4);
		gotoxy(35,2);
		foreColor(12);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	} 
	if(file.good())
	{
		int i=6;
		ds.header();
		DrawRectangle(10,4,70,20,11);
		file.read((char*)&ds,sizeof(DrinkInStock));
		while(file.eof()!=true)
		{
			i++;
			gotoxy(15,i);
			ds.outputData();
			file.read((char*)&ds,sizeof(DrinkInStock));
		}
		file.close();
		
		char OrderID[30];
		file.open("DrinkInformation.bin", ios::out | ios::binary | ios::app);
		file1.open("OrderList.bin", ios::in | ios::binary | ios::app);
		file.read((char*)&ds,sizeof(DrinkInStock));
		while(file.eof()!=true)
		{
			DrawRectangle(25,23,40,1,6);
			foreColor(13);
			gotoxy(10,24);
			cout <<"\t\t\t    Input ID to Order : "; cin.getline(OrderID,30) ; fflush(stdin); cin.clear();
			if(strcmpi(OrderID,ds.barcode)==0)
			{
				file1.write((char*)&ds,sizeof(DrinkInStock));
			}					
		}
			
	}	
	file.close();
}

void InsertDrink()
{
	file.open("DrinkInformation.bin", ios::out | ios::binary | ios::app);
	ds.inputData();
	file.write((char*)&ds,sizeof(DrinkInStock));
	file.close();
}

void ViewAllDrink()
{
	
	file.open("DrinkInformation.bin", ios::in | ios::binary);
	if(file.fail())
	{	
		DrawRectangle(2,0,86,28,4);
		gotoxy(35,2);
		foreColor(12);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	} 
	if(file.good())
	{
		int i=6;
		ds.header();
		DrawRectangle(10,4,70,20,11);
		file.read((char*)&ds,sizeof(DrinkInStock));
		while(file.eof()!=true)
		{
			i++;
			gotoxy(15,i);
			ds.outputData();
			file.read((char*)&ds,sizeof(DrinkInStock));
		}
		
	}
	
	file.close(); 
}

void SearchDrink()
{
	char sid[30];
	bool isFound = false;
	DrawRectangle(2,0,86,28,4);
	file.open("DrinkInformation.bin", ios::in | ios::binary);
	if(file.fail())
	{			
		gotoxy(35,2);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	} 
	if(file.good())
	{
		
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t Search Drink Information";
		gotoxy(5,6);
		foreColor(13);
		cout << "\t\t\t Enter Drink Barcode you wanna Search : "; cin.get(sid,30); fflush(stdin); cin.clear();
		file.read((char*)&ds,sizeof(DrinkInStock));
		while(file.eof()!=true)
		{
			if(strcmpi(sid,ds.barcode)==0)
			{
				system("cls");
				ds.header();
				gotoxy(15,7);
				ds.outputData();
				ds.footer();
				isFound = true;
			}
			file.read((char*)&ds,sizeof(DrinkInStock));
		}
		if(isFound==false)
		{
			gotoxy(5,10);
			foreColor(12);
			cout <<"\t\t\t Warning: Drink Barcode was not found!!";
		}
	}
	file.close();
}

void UpdateDrink()
{
	file.open("DrinkInformation.bin", ios::out | ios::binary | ios::in);
	char sid[30];
	bool isFound = false;
	DrawRectangle(2,0,86,28,4);

	if(file.fail())
	{			
		gotoxy(35,2);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	} 
	if(file.good())
	{
		
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t Update Drink Information";
		gotoxy(5,6);
		foreColor(13);
		cout << "\t\t\t Enter Drink barcode you wanna Update : "; cin.get(sid,30); fflush(stdin); cin.clear();
		file.read((char*)&ds,sizeof(DrinkInStock));
		while(file.eof()!=true)
		{
			if(strcmpi(sid,ds.barcode)==0)
			{
				system("cls");
				
				gotoxy(15,7);
				ds.editData();
				int lastRead = file.tellg();
				file.seekp(lastRead-sizeof(DrinkInStock));
				file.write((char*)&ds,sizeof(DrinkInStock));
				ds.footer();
				isFound = true;
			}
			file.read((char*)&ds,sizeof(DrinkInStock));
		}
		if(isFound==false)
		{
			gotoxy(5,10);
			foreColor(12);
			cout <<"\t\t\t Warning: Drink barcode was not found!!";
		}
	}
	file.close();
}	

void DeleteDrink()
{
	DrawRectangle(2,0,86,28,4);
	fstream backup;
	file.open("DrinkInformation.bin", ios::out | ios::binary | ios::in);
	backup.open("Temp.bin", ios::out | ios::binary);
	char sid[30];
	bool isFound = false;
	if(file.fail())
	{			
		gotoxy(35,2);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	}
	if(file.good())
	{
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t Delete Drink Information";
		gotoxy(5,6);
		foreColor(13);
		cout << "\t\t\t Enter Drink barcode you wanna Delete : "; cin.get(sid,30); fflush(stdin); cin.clear();
		file.read((char*)&ds,sizeof(DrinkInStock));	
		while(file.eof()!=true)
		{
			if(strcmpi(sid,ds.barcode)==0)
			{
				isFound=true;
			}
			else
			{
				backup.write((char*)&ds,sizeof(DrinkInStock));
			}
			file.read((char*)&ds,sizeof(DrinkInStock));	
		}
		if(isFound == false)
		{
			gotoxy(15,10);
			foreColor(12); cout << "\t\t      ERROR: No Barcode found!!" << endl;
		} 
		/*if(isFound == true) 
		{
			gotoxy(15,10);
			foreColor(2); cout << "\t\t      Data is deleted Successfully..."<< endl;
		}*/
	}
	file.close();
	backup.close();
	remove("DrinkInformation.bin");
	rename("Temp.bin","DrinkInformation.bin"); 
}



#endif