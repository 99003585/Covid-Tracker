#include <covidtracker.h>


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct covid
{
    char state[25];
    int confirmed,active,recovered,deceased,other;
};


int valid_choice(int choice)
{
    if(choice == 1|| choice == 2|| choice == 3|| choice == 4|| choice == 5|| choice == 6)
        return 1;
    return 0;
}


void menu()
{
    int choice;
    system("clear");
    printf("\n\n\n\n\n\t\t\t<----- MENU ----->");
    printf("\n\t\t\t\n\t\t\t1 : Insert Record.");
    printf("\n\t\t\t2 : Display Record.");
    printf("\n\t\t\t3 : Search Record.");
    printf("\n\t\t\t4 : Update Record.");
    printf("\n\t\t\t5 : Delete Record.");
    printf("\n\t\t\t6 : Exit.");
    printf("\n\t\t\t\n\t\t\tEnter your choice : ");
    scanf("%d",&choice);

    while(!valid_choice(choice))
    {
        printf("\n\t\t\tInvalid Option!!! Try again !!!\n");
        printf("\n\t\t\tEnter valid choice  : ");
        scanf("%d",&choice);
    }


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
        printf("\n\t\t\t\n\t\t\tInvalid Option!!! Try again !!!\n\t\t\t");
    }
}


void insert()
{
    FILE *fp;
    struct covid c;
    char another = 'y';
    char key;
    system("clear");

    fp = fopen("file.txt","ab+");
    if(fp == NULL)
    {
        printf("\n\t\t\tCannot Open!");
        return;
    }
    while(another == 'y')
    {
        printf("\n\n\n\n\n\n\t\t\t<--:ENTER NEW RECORD:-->");
        printf("\n\t\t\t\n\t\t\tEnter state name : ");
        scanf("%24s",c.state);
        fflush(stdin);
        printf("\n\t\t\tEnter confirmed  : ");
        scanf("%d",&c.confirmed);
        printf("\n\t\t\tEnter active     : ");
        scanf("%d",&c.active);
        printf("\n\t\t\tEnter recovered  : ");
        scanf("%d",&c.recovered);
        printf("\n\t\t\tEnter deceased   : ");
        scanf("%d",&c.deceased);
        printf("\n\t\t\tEnter other      : ");
        scanf("%d",&c.other);

        fwrite(&c,sizeof(c),1,fp);
        printf("\n\t\t\t\n\t\t\tWant to add of another record? Then press 'y' else 'n'. ");
        fflush(stdin);
        scanf("%3s",&another);
        system("clear");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress Enter key to continue.");
    getchar();
    getchar();
    menu();
}


void display()
{
    FILE *fp;
    int i=1,j;
    char key;
    struct covid c;
    system("clear");

    printf("\n\n\n\n\n\n\t\t\t<--:VIEW RECORD:-->");
    printf("\n\t\t\t\n\t\t\tS.No    STATE NAME            CONFIRMED    ACTIVE    RECOVERED    DECEASED    OTHERS");
    printf("\n\t\t\t------------------------------------------------------------------------------------");
    fp = fopen("file.txt","rb+");
        if(fp == NULL)
        {
            printf("\n\t\t\tCannot Open!");
            return;
        }
    //j=8;
    while(fread(&c,sizeof(c),1,fp) == 1){
        printf("\n\t\t\t%-8d%-23s%-13d%-10d%-13d%-12d%-9d",i,c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);
        i++;
       // j++;
    }
    fclose(fp);
    printf("\n\t\t\t\n\t\t\t\n\t\t\tPress Enter key to continue.");
    getchar();
    getchar();
    menu();
}


void search()
{
    FILE *fp;
    struct covid c;
    char st[25];
    char key;
    system("clear");

    printf("\n\n\n\n\n\n\t\t\t<--:SEARCH RECORD:-->");
    printf("\n\t\t\t\n\t\t\t Enter state to be searched : ");
    fflush(stdin);
    scanf("%24s",st);

    fp = fopen("file.txt","rb+");
        if(fp == NULL)
        {
            printf("\n\t\t\tCannot Open!");
            return;
        }
    while(fread(&c,sizeof(c),1,fp) == 1 )
    {
        if(strcmp(c.state,st)==0)
        {
            printf("\n\t\t\t\n\t\t\tState     : %s",c.state);
            printf("\n\t\t\tConfirmed : %d",c.confirmed);
            printf("\n\t\t\tActive    : %d",c.active);
            printf("\n\t\t\tRecovered : %d",c.recovered);
            printf("\n\t\t\tDeceased  : %d",c.deceased);
            printf("\n\t\t\tOthers    : %d",c.other);
        }
    }
        fclose(fp);
        printf("\n\n\n\t\t\tPress Enter key to continue.");
        getchar();
        getchar();
        menu();
}


void update()
{
    char st[25];
    char key;
    FILE *fp;
    struct covid c;
    system("clear");

    printf("\n\n\n\n\n\n\t\t\t<--:MODIFY RECORD:-->");
    printf("\n\t\t\t\n\t\t\t Enter state to be updated : ");
    fflush(stdin);
    scanf("%24s",st);

    fp = fopen("file.txt","rb+");
    if(fp == NULL){
        printf("\n\t\t\tCannot Open!");
        return;
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&c,sizeof(c),1,fp) == 1)
    {
        if(strcmp(c.state,st) == 0)
        {
            printf("\n\t\t\t\n\t\t\tSTATE NAME            CONFIRMED    ACTIVE    RECOVERED    DECEASED    OTHERS");
            printf("\n\t\t\t------------------------------------------------------------------------------------");
            printf("\n\t\t\t%-23s%-13d%-10d%-13d%-12d%-9d",c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);
            
            printf("\n\t\t\t\n\t\t\t--- Enter latest updates ---");
            printf("\n\t\t\t\n\t\t\tEnter state name: ");
            scanf("%24s",c.state);
            fflush(stdin);
            printf("\n\t\t\tEnter confirmed : ");
            scanf("%d",&c.confirmed);
            printf("\n\t\t\tEnter active    : ");
            scanf("%d",&c.active);
            printf("\n\t\t\tEnter recovered : ");
            scanf("%d",&c.recovered);
            printf("\n\t\t\tEnter deceased  : ");
            fflush(stdin);
            scanf("%d",&c.deceased);
            printf("\n\t\t\tEnter other     : ");
            fflush(stdin);
            scanf("%d",&c.other);

            fseek(fp ,-sizeof(c),SEEK_CUR);
            fwrite(&c,sizeof(c),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress Enter key to continue.");
    getchar();
    getchar();
    menu();
}


void delete()
{
    char st[25];
    char key;
    FILE *fp,*ft;
    struct covid c;
    system("clear");

    printf("\n\n\n\n\n\n\t\t\t<--:DELETE RECORD:-->");
    printf("\n\t\t\t\n\t\t\tEnter the state name to be deleted : ");
    fflush(stdin);
    scanf("%24s",st);

    fp = fopen("file.txt","rb+");
    if(fp == NULL){
        printf("\n\t\t\tCannot Open!");
        return;
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        printf("\n\t\t\tCannot Open!");
        exit(1);
        //return;

    }

    while(fread(&c,sizeof(c),1,fp) == 1){
        if(strcmp(c.state,st)!=0)
            fwrite(&c,sizeof(c),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("file.txt");
    rename("temp.txt","file.txt");
    printf("\n\n\n\t\t\tPress Enter key to continue.");
    getchar();
    getchar();
    menu();
}
