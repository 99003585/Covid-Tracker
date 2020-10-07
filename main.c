#include <covidtracker.h>
#include <test_covidtracker.h>

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


struct covid
{
    char state[25];
    int confirmed,active,recovered,deceased,other;
};


void main()
{
    system("color 1f");
    gotoxy(15,8);
    printf("<------ COVID TRACKER SYSTEM ------>");
    menu();

	/* Calling test main*/
    
    test_main();								/* Add function call */
	return 0;
}




