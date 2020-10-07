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


void insert()
{
    FILE *fp;
    struct covid c;
    char another ='y';
    system("cls");

    fp = fopen("file.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Cannot Open!");
        return;
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ENTER NEW RECORD:-->");
        gotoxy(10,5);
        printf("\nEnter state name : ");
        scanf("%s",c.state);
        fflush(stdin);
        gotoxy(10,6);
        printf("\nEnter confirmed  : ");
        scanf("%d",&c.confirmed);
        gotoxy(10,7);
        printf("\nEnter active     : ");
        scanf("%d",&c.active);
        gotoxy(10,8);
        printf("\nEnter recovered  : ");
        scanf("%d",&c.recovered);
        gotoxy(10,9);
        printf("\nEnter deceased   : ");
        scanf("%d",&c.deceased);
        gotoxy(10,10);
        printf("\nEnter other      : ");
        scanf("%d",&c.other);

        fwrite(&c,sizeof(c),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'. ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}


void display()
{
    FILE *fp;
    int i=1,j;
    struct covid c;
    system("cls");

    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No    STATE NAME            CONFIRMED    ACTIVE    RECOVERED    DECEASED    OTHERS");
    gotoxy(10,6);
    printf("------------------------------------------------------------------------------------");
    fp = fopen("file.txt","rb+");
        if(fp == NULL)
        {
            gotoxy(10,8);
            printf("Cannot Open!");
            return;
        }
    j=8;
    while(fread(&c,sizeof(c),1,fp) == 1){
        gotoxy(10,j);
        printf("%-8d%-23s%-13d%-10d%-13d%-12d%-9d",i,c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}


void search()
{
    FILE *fp;
    struct covid c;
    char st[25];;
    system("cls");

    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("\n\n Enter state to be searched : ");
    fflush(stdin);
    scanf("%s",st);

    fp = fopen("file.txt","rb+");
        if(fp == NULL)
        {
            gotoxy(10,6);
            printf("Cannot Open!");
            return;
        }
    while(fread(&c,sizeof(c),1,fp) == 1 )
    {
        if(strcmp(c.state,st)==0)
        {
            gotoxy(10,8);
            printf("State     : %s",c.state);
            gotoxy(10,9);
            printf("Confirmed : %d",c.confirmed);
            gotoxy(10,10);
            printf("Active    : %d",c.active);
            gotoxy(10,11);
            printf("Recovered : %d",c.recovered);
            gotoxy(10,12);
            printf("Deceased  : %d",c.deceased);
            gotoxy(10,13);
            printf("Others    : %d",c.other);
        }
    }
        fclose(fp);
        gotoxy(10,16);
        printf("Press any key to continue.");
        getch();
        menu();
}


void update()
{
    char st[25];
    FILE *fp;
    struct covid c;
    system("cls");

    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("\n\n Enter state to be updated : ");
    fflush(stdin);
    scanf("%s",st);

    fp = fopen("file.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Cannot Open!");
        return;
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&c,sizeof(c),1,fp) == 1)
    {
        if(strcmp(c.state,st) == 0)
        {
            gotoxy(10,9);
            printf("STATE NAME            CONFIRMED    ACTIVE    RECOVERED    DECEASED    OTHERS");
            gotoxy(10,10);
            printf("----------------------------------------------------------------------------");
            gotoxy(10,12);
            printf("%-23s%-13d%-10d%-13d%-12d%-9d",c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);

            gotoxy(10,15);
            printf("--- Enter latest updates ---");
            gotoxy(10,16);
            printf("\nEnter state name: ");
            scanf("%s",c.state);
            fflush(stdin);
            gotoxy(10,17);
            printf("\nEnter confirmed : ");
            scanf("%d",&c.confirmed);
            gotoxy(10,18);
            printf("\nEnter active    : ");
            scanf("%d",&c.active);
            gotoxy(10,19);
            printf("\nEnter recovered : ");
            scanf("%d",&c.recovered);
            gotoxy(10,20);
            printf("\nEnter deceased  : ");
            fflush(stdin);
            scanf("%d",&c.deceased);
            gotoxy(10,21);
            printf("\nEnter other     : ");
            fflush(stdin);
            scanf("%d",&c.other);

            fseek(fp ,-sizeof(c),SEEK_CUR);
            fwrite(&c,sizeof(c),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,22);
    printf("\nPress any key to continue.");
    getch();
    menu();
}


void delete()
{
    char st[25];
    FILE *fp,*ft;
    struct covid c;
    system("cls");

    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter the state name to be deleted : ");
    fflush(stdin);
    scanf("%s",st);

    fp = fopen("file.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Cannot Open!");
        return;
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Cannot Open!");
        return;

    }

    while(fread(&c,sizeof(c),1,fp) == 1){
        if(strcmp(c.state,st)!=0)
            fwrite(&c,sizeof(c),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("file.txt");
    rename("temp.txt","file.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}


void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
