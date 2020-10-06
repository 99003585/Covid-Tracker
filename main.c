#include <covidtracker.h>

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
}


void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<----- MENU ----->");
    gotoxy(10,6);
    printf("1 : Insert Record.");
    gotoxy(10,7);
    printf("2 : Display Record.");
    gotoxy(10,8);
    printf("3 : Search Record.");
    gotoxy(10,9);
    printf("4 : Update Record.");
    gotoxy(10,10);
    printf("5 : Delete Record.");
    gotoxy(10,11);
    printf("6 : Exit.");
    gotoxy(10,14);
    printf("Enter your choice.");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        insert();
        break;

    case 2:
        display();
        break;

    case 3:
        search();
        break;

    case 4:
        update();
        break;

    case 5:
        delete();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf(" Invalid Option!!! Try again !!!\n");
    }
}


