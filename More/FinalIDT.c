#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
    int id;
    char name[20];
    int age;
    int salary;
};
struct data *table=NULL;
int len=0,mamory=1;
void insert()
{
    /*int num;*/
    len++;
    if(len==mamory)
    {
        mamory=len*2;
        if ( (table=(struct data*)realloc(table,mamory*sizeof(struct data)))==0)
        {
            printf("ERROR!");
        }
    }
    printf("Enter the \" ID \" of Client: ");
    scanf("%d",&(table+(len-1))->id);
    printf("Enter the \" Name \" of Client: ");
    scanf("%s",(table+(len-1))->name);
    printf("Enter the \" Age \" of Client: ");
    scanf("%d",&(table+(len-1))->age);
    printf("Enter the \" Salary \" of Client: ");
    scanf("%d",&(table+(len-1))->salary);
}
void print(int i)
{
    printf("    %d",(table+i)->id);
    for(int j=0; j<8; j++){ printf(" ");}
    printf("%s",(table+i)->name);
    for(int k=0; k<(25-strlen((table+i)->name)); k++) {printf(" ");}
    printf("%d",(table+i)->age);
    for(int l=0; l<11; l++) {printf(" ");}
    printf("%d\n",(table+i)->salary);
}
void printTable()
{
    printf("     ID       Name                   Age          salary\n");
    printf("    ----     ------                 -----        --------\n\n");
    for(int i=0; i<len; i++)
    {
        print(i);
    }
}
int sum()
{
    int i;
    int sum=0;
    for(i=0; i<len; i++)
    {
        sum+= (table+i)->salary;
    }
    return sum;
}
int searchClient(int id)
{
    for(int i=0; i<len; i++)
    {
        if((table+i)->id==id)
        {
            return(i);
        }
    }
    return(-1);
}
void findMaxSalary()
{
    int max=(table+0)->salary;
    int store;
    for(int i=0; i<len; i++)
    {
        if((table+i)->salary>max) store=i;
    }
    printf("\n\nHighest Paid Client Name = %s || Age = %d || Salary = %d\n\n",(table+store)->name,(table+store)->age,(table+store)->salary);
}
void findMinSalary()
{
    int min=(table+0)->salary;
    int store;
    for(int i=0; i<len; i++)
    {
        if((table+i)->salary<min) store=i;
    }
    printf("\n\nLowest Paid Client Name = %s || Age = %d || Salary = %d\n\n",(table+store)->name,(table+store)->age,(table+store)->salary);
}
void shortTableSalary()
{
    int *copyTable[len],*temp;
    for(int i=0; i<len; i++)
    {
        copyTable[i]=&(table+i)->salary;
    }
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(*copyTable[j]<*copyTable[i])
            {
                temp=copyTable[i];
                copyTable[i]=copyTable[j];
                copyTable[j]=temp;
            }
        }
    }
    printf("\n                Client Sorted Table By Salary");
    printf("\n-----------------------------------------------------------------\n");
    printf("     ID        Name                     Age          salary\n");
    printf("    ----      ------                   -----        --------\n\n");
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(*copyTable[i]==(table+j)->salary) print(j);
        }
    }
}
void shortTableAge()
{
    int *copyTable[len],*temp;
    for(int i=0; i<len; i++)
    {
        copyTable[i]=&(table+i)->age;
    }
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(*copyTable[j]<*copyTable[i])
            {
                temp=copyTable[i];
                copyTable[i]=copyTable[j];
                copyTable[j]=temp;
            }
        }
    }
    printf("\n                   Client Sorted Table By Age");
    printf("\n-----------------------------------------------------------------\n");
    printf("     ID        Name                     Age          salary\n");
    printf("    ----      ------                   -----        --------\n\n");
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(*copyTable[i]==(table+j)->age) print(j);
        }
    }
}
int removeClient(int pos)
{

    for(int i=pos,j=pos+1; i<len; i++,j++)
    {
        (table+i)->id=(table+j)->id;
        strcpy((table+i)->name,(table+j)->name);
        (table+i)->age=(table+j)->age;
        (table+i)->salary=(table+j)->salary;
    }
    len--;
    if(len<mamory/2)
        table=(struct data*)realloc(table,mamory/2*sizeof(struct data));
    return 1;

}
int main()
{
    printf("***Implementation of Dynamic Table***\n");
    int choice;
    while(1)
    {
        printf("\n----------------------------\n");
        printf("        Table Menu\n");
        printf("----------------------------\n");
        printf(" 1 : Insert Data\n");
        printf(" 2 : Print table\n");
        printf(" 3 : Sum of Clients Salary\n");
        printf(" 4 : Search Client By ID\n");
        printf(" 5 : Print maximum Salary Client Data\n");
        printf(" 6 : Print minimum Salary Client Data\n");
        printf(" 7 : Sort table by Salary\n");
        printf(" 8 : Sort table by Age\n");
        printf(" 9 : Average Salary of Client\n");
        printf(" 10: Remove Client\n");
        printf(" 0 : Exit\n");
        printf(" Choose your option :  ");

        scanf("%d",&choice);

        if(choice==1)
        {
            insert();
        }
        if(choice==2)
        {
            if(table!=NULL)
            {
                printf("\n                          Client Table\n");
                printf("-----------------------------------------------------------------\n\n");
                printTable();
            }
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");

        }
        if(choice==3)
        {
            if(table!=NULL)
            {
                long long int total=sum();
                printf("The Sum of the Salary is %lld\n",total);
            }
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==4)
        {
            if(table!=NULL)
            {
                int id;
                printf("Enter Client Id:  ");
                scanf("%d",&id);

                int found=searchClient(id);
                if(found==-1)
                {
                    printf(" Did not find the Client\n");
                }
                else
                {
                    printf("\n\nID Found.\nName=%s || Age=%d || Salary=%d\n\n",(table+found)->name,(table+found)->age,(table+found)->salary);
                }
            }
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==5)
        {
            if(table!=NULL) findMaxSalary();
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==6)
        {
            if(table!=NULL) findMinSalary();
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==7)
        {
            if(table!=NULL) shortTableSalary();
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==8)
        {
            if(table!=NULL) shortTableAge();
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==9)
        {
            if(table!=NULL)
            {
                double average;
                long long int total=sum();
                average=(total)/len;
                printf("len=%d\n",len);
                printf("\n\nAverage of Clients Salary is = %0.2f\n\n",average);
            }
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");
        }
        if(choice==10)
        {
            if(table!=NULL)
            {
                int id;
                printf("\n\nEnter the Id of the Client: ");
                scanf("%d",&id);
                int found=searchClient(id);
                if(found==-1)
                {
                    printf(" Did not find the Client\n");
                }
                else
                {
                    int deleted=removeClient(found);
                    if(deleted==1)
                    {
                        printf("\n\nClient Removed Successfully!\n\n");
                    }
                    else
                    {
                        printf("\n\nSomething is Wrong!\n\n");
                    }
                }
            }
            else printf("\nThere are No Data in the Table. Please Insert Data First.\n");


        }
        if(choice==0) exit(0);
    }

}

