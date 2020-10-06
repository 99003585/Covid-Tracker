#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void insert();
void display();
void search();

struct covid
{
    char state[25];
    int confirmed,active,recovered,deceased,other;
};
struct covid c;


void main()
{
    //system("color 1f");
    int choice;
    system("cls");
    while (choice!=4)
    {
        system("cls");

        printf("Welcome!!!");
        printf("\n 1- Insert\n 2- Display\n 3- Search\n 4- Delete\n 5- Update\n 6- Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: system("cls");
                insert();
                break;
            case 2: system("cls");
                display();
                break;
            case 3: system("cls");
                search();
                break;
            case 4: exit(1);
            default:
                 printf(" Invalid Option!!! Try again !!!\n");
        }
        printf("\nPress any key...");
        getch();
    }
}

void insert()
{
    FILE *fp;
    fp = fopen("file.txt","ab+");
        if(fp == NULL)
        {
            printf("Cannot Open!");
            return;
        }

    printf("Prev stored data");
    display();

    printf("'Enter New Data'\n");
    printf("\nEnter state name");
    scanf("%s",c.state);
    fflush(stdin);
    printf("\nenter confirmed:");
    scanf("%d",&c.confirmed);
    printf("\nenter active:");
    scanf("%d",&c.active);
    printf("\nenter recovered:");
    scanf("%d",&c.recovered);
    printf("\nenter deceased");
    scanf("%d",&c.deceased);
    printf("\nenter other");
    scanf("%d",&c.other);

    fwrite(&c, sizeof(c), 1, fp);
    {
        printf("\n\nInserted Successfully!!");
    }
    fclose(fp);
    printf("Updated Record");
    display();
}

void display()
{
    FILE *fp;
    fp = fopen("file.txt","rb");
        if(fp == NULL)
        {
            printf("Cannot Open!");
            return;
        }
    printf("\n\n***Details are as follows***");
    printf("\nSTATE\tCONFIRMED\tACTIVE\tRECOVERED\tDECEASED\tOTHERS\n\n");

    //while(fread(&c,sizeof(c),1,fp)==1)
    while((fread(&c,sizeof(c),1,fp))>0)
    {
        printf("%s  \t%d  \t%d\t%d\t%d\t%d\n",c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);
    }
    fclose(fp);
}

void search()
{
    char st[25];
    int flag=0;
    FILE *fp;
    fp = fopen("file.txt","rb");
        if(fp == NULL)
        {
            printf("Cannot Open!");
            return;
        }
    printf("\n\n Enter state to be searched : ");
    scanf("%s",st);
    while(fread(&c,sizeof(c),1,fp)>0 && flag==0)
        if(strcmp(c.state,st)==0)
        {
            flag=1;
            printf("\n\nSearch successfull & updates are as follows:");
            printf("\nSTATE\tCONFIRMED\tACTIVE\tRECOVERED\tDECEASED\tOTHERS\n\n");
            printf("%s  \t%d  \t%d \t%d \t%d \t%d\n",c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);
        }
        if (flag==0)
        {
            printf("\n\n*NO SUCH RECORD*\n");
        }
        fclose(fp);
}

