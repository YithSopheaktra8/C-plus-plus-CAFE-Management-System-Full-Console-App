#ifndef ALLSTAFFFILEIO________H____
#define ALLSTAFFFILEIO________H____

#include "..\HeaderFile\AllStaff.h"
#include<fstream>

fstream file1;
Staff st;

void InsertStaff()
{
	file1.open("StaffInformation.bin", ios::out | ios::binary | ios::app);
	st.InputStaff();
	file1.write((char*)&st,sizeof(Staff));
	file1.close();
}

void ViewAllStaff()
{
	file1.open("StaffInformation.bin", ios::in | ios::binary);
	if(file1.fail())
	{	
		DrawRectangle(2,0,86,28,4);
		gotoxy(35,2);
		foreColor(12);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	}
	if(file1.good())
	{
		int i=6;
		st.Header();
		file1.read((char*)&st,sizeof(Staff));
		while(file1.eof()!=true)
		{
			i++;
			gotoxy(15,i);
			st.ViewStaff();
			file1.read((char*)&st,sizeof(Staff));
		}
		
	}	
	file1.close();  
}

void SearchStaff()
{
	char sid[30];
	bool isFound = false;
	DrawRectangle(2,0,86,28,4);
	file1.open("StaffInformation.bin", ios::in | ios::binary);
	if(file1.fail())
	{			
		gotoxy(35,2);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	} 
	if(file1.good())
	{
		
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t Search Staff Information";
		gotoxy(5,6);
		foreColor(13);
		cout << "\t\t\t Enter Staff ID you wanna Search : "; cin.get(sid,30); fflush(stdin); cin.clear();
		file1.read((char*)&st,sizeof(Staff));
		while(file1.eof()!=true)
		{
			if(strcmpi(sid,st.id)==0)
			{
				system("cls");
				st.Header();
				gotoxy(15,7);
				st.ViewStaff();
				st.Footer();
				isFound = true;
			}
			file1.read((char*)&st,sizeof(Staff));
		}
		if(isFound==false)
		{
			gotoxy(5,10);
			foreColor(12);
			cout <<"\t\t\t Warning: Staff ID was not found!!";
		}
	}
	file1.close();
}

void UpdateStaff()
{
	file1.open("StaffInformation.bin", ios::in | ios::binary | ios::out);
	char sid[30];
	bool isFound = false;
	DrawRectangle(2,0,86,28,4);

	if(file1.fail())
	{			
		gotoxy(35,2);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	} 
	if(file1.good())
	{
		
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t Update Staff Information";
		gotoxy(5,6);
		foreColor(13);
		cout << "\t\t\t Enter Staff ID you wanna Update : "; cin.get(sid,30); fflush(stdin); cin.clear();
		file1.read((char*)&st,sizeof(Staff));
		while(file1.eof()!=true)
		{
			if(strcmpi(sid,st.id)==0)
			{
				system("cls");
				
				gotoxy(15,7);
				st.EditStaff();
				int lastRead = file1.tellg();
				file1.seekp(lastRead-sizeof(Staff));
				file1.write((char*)&st,sizeof(Staff));
				st.Footer();
				isFound = true;
			}
			file1.read((char*)&st,sizeof(Staff));
		}
		if(isFound==false)
		{
			gotoxy(5,10);
			foreColor(12);
			cout <<"\t\t\t Warning: Staff ID was not found!!";
		}
	}
	file1.close();
}

void DeleteStaff()
{
	DrawRectangle(2,0,86,28,4);
	fstream backup1;
	file1.open("StaffInformation.bin", ios::in | ios::binary | ios::out);
	backup1.open("Temp1.bin", ios::out | ios::binary);
	char sid[30];
	bool isFound = false;
	if(file1.fail())
	{			
		gotoxy(35,2);
		cout << "File was not found!!!!" << endl;
		gotoxy(33,14);
	}
	if(file1.good())
	{
		DrawRectangle(10,1,70,1);
		gotoxy(10,2);
		cout << "\t\t\t Delete Staff Information";
		gotoxy(5,6);
		foreColor(13);
		cout << "\t\t\t Enter Staff ID you wanna Delete : "; cin.get(sid,30); fflush(stdin); cin.clear();
		file1.read((char*)&st,sizeof(Staff));
		while(file1.eof()!=true)
		{
			if(strcmpi(sid,st.id)==0)
			{
				isFound=true;
			}
			else
			{
				backup1.write((char*)&st,sizeof(Staff));
			}
			file1.read((char*)&st,sizeof(Staff));
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
	file1.close();
	backup1.close();
	remove("StaffInformation.bin");
	rename("Temp1.bin","StaffInformation.bin"); 
}

#endif