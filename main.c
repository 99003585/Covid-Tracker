#include <covidtracker.h>


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct covid
{
    char state[25];
    int confirmed,active,recovered,deceased,other;
};


void main()
{
    printf("\n\n\n\n\t\t\t<------ COVID TRACKER SYSTEM ------>");
    menu();
}




