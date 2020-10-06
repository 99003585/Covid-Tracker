#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void insert();
void display();
void search();
void delete();
void update();

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
    while (choice!=6)
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
            case 4: system("cls");
                delete();
                break;
            case 5: system("cls");
                update();
                break;
            case 6: exit(1);
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

void delete()
{
    char st_name[25];
    int flag=0;
    FILE *fp,*ft;
    fp = fopen("file.txt","rb");
        if(fp == NULL)
        {
            printf("Cannot Open!");
            return;
        }
    printf("\n\n***Previous Data***");
    display();

    printf("\n\n Enter state to be deleted : ");
    scanf("%s",st_name);

    ft= fopen("newfile.txt","ab+");
     while(fread(&c,sizeof(c),1,fp)>0)
        if(strcmp(st_name,c.state)!=0)
        {
           // printf("\n\nRecord Deleted Successfully!!!");
            fwrite(&c,sizeof(c),1,ft);

        }
        else
            flag=1;
        if(flag==0)
        {
             printf("*No such state found*");
        }
    fclose(fp);
    fclose(ft);
    remove("file.txt");
    rename("newfile.txt","file.txt");
    printf("\n\n**Updated Data**");
    display();
}

void update()
{
    char st[25];
    int found=0;
    FILE *fp;
    system("cls");
    printf("\n\n Enter state to be updated : ");
    scanf("%s",st);
    fp = fopen("file.txt","rb+");
    while((fread(&c,sizeof(c),1,fp))>0 && found==0)
    {
     if(strcmp(c.state,st)==0)
            {
                printf("\nSTATE\tCONFIRMED\tACTIVE\tRECOVERED\tDECEASED\tOTHERS\n\n");
                printf("%s  \t%d  \t%d \t%d \t%d \t%d\n",c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);

                printf("Enter new record : ");
                printf("\nUpdated state name : ");
                scanf("%s",c.state);
                fflush(stdin);
                printf("\nUpdated confirmed : ");
                scanf("%d",&c.confirmed);
                printf("\nUpdated active : ");
                scanf("%d",&c.active);
                printf("\nUpdated recovered : ");
                scanf("%d",&c.recovered);
                printf("\nUpdated deceased : ");
                scanf("%d",&c.deceased);
                printf("\nUpdated other : ");
                scanf("%d",&c.other);

                fseek(fp,-(long)sizeof(c),1);
                fwrite(&c,sizeof(c),1,fp);
                printf("\n\n\t Record Updated");
                found=1;
            }
         }
    fclose(fp);
    if(found==0)
    printf("\n\n Record Not Found ");
}

/*

void update()
{
    char stat[25];
    int flag=0;
    FILE *fp;
    fp = fopen("file.txt","rb+");
    if(fp == NULL)
        {
            printf("State not added yet.!");
            return;
        }
    else
    {
        system("cls");
        printf("\n\n Enter state to be updated : ");
        scanf("%s",stat);

        printf("\n\n Previous record of this state : ");

        while(fread(&c,sizeof(c),1,fp)>0 && flag==0)
        {
            if(strcmp(c.state,stat)==0)
            {
            //flag=1;
                printf("\nSTATE\tCONFIRMED\tACTIVE\tRECOVERED\tDECEASED\tOTHERS\n\n");
                printf("%s  \t%d  \t%d \t%d \t%d \t%d\n",c.state,c.confirmed,c.active,c.recovered,c.deceased,c.other);

                printf("Enter new record : ");
                printf("\nUpdated state name : ");
                scanf("%s",c.state);
                //fflush(stdin);
                printf("\nUpdated confirmed : ");
                scanf("%d",&c.confirmed);
                printf("\nUpdated active : ");
                scanf("%d",&c.active);
                printf("\nUpdated recovered : ");
                scanf("%d",&c.recovered);
                printf("\nUpdated deceased : ");
                scanf("%d",&c.deceased);
                printf("\nUpdated other : ");
                scanf("%d",&c.other);

                fseek(fp,-sizeof(c),SEEK_CUR);
                fwrite(&s,sizeof(c),1,fp);
                flag=1;
                break;
            }
            fflush(stdin);
        }
        if(flag==1)
        {
             printf("Updation Successfull!!");

        }
        else
        {
            printf(" \nData Not Found");
        }
        fclose(fp);
	}

}

*/

