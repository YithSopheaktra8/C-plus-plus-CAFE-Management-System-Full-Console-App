// File Called Header File  -> Don't have main program
//-----------------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
/////////////////////////////////////////////////////////////////////////////////////
char* hidePassword(char password[])// char password[]  Is Parameter
{
	char key;// Local Variable
	int p2 = 0;
    // create own input
	while(1)
	{
		key = getch();
		if(key == 13)// 13 mean key enter
		{
			break;
		}
		else if(key == 8)// key backspace
		{
			if(p2>0)
			{
				printf("\b \b");
				p2--;
				//set empty
				password[p2] = '\0';
			}
		}
		else if( key == 32 || key == 9)
		{
			continue;// skip 
		}
		else
		{
			// hide password
			printf("*");
			// set value
			password[p2++] = key;
		}
	}
	// empty Char Array
	password[p2] = '\0';
	
	return password;
}
//-----------------------------------------------------------------------------------