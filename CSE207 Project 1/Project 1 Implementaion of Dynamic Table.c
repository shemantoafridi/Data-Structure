#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct info
{
    int id;
    char name[20];
    int age;
    double cgpa;
};

struct info *table=NULL;
int len=0,mem=1;

void insert()
{
    len++;
    if(len==mem)
    {
        mem=len*2;
        if ( (table=(struct info*)realloc(table,mem*sizeof(struct info)))==0)
        {
            printf("ERROR!");
        }
    }
    printf("Enter Student's ID: ");
    scanf("%d",&(table+(len-1))->id);
    printf("Enter Student's Name: ");
    scanf("%s",(table+(len-1))->name);
    printf("Enter Student's Age: ");
    scanf("%d",&(table+(len-1))->age);
    printf("Enter Student's CGPA: ");
    scanf("%lf",&(table+(len-1))->cgpa);
}

void print(int i)
{
    printf("    %d",(table+i)->id);
    for(int j=0; j<5; j++){ printf(" ");}
    printf("%s",(table+i)->name);
    for(int k=0; k<(25-strlen((table+i)->name)); k++) {printf(" ");}
    printf("%d",(table+i)->age);
    for(int l=0; l<11; l++) {printf(" ");}
    printf("%lf\n",(table+i)->cgpa);
}

void printTable()
{
    printf("     ID       Name                   Age           CGPA\n");
    printf("    ----     ------                 -----        --------\n\n");
    for(int i=0; i<len; i++)
    {
        print(i);
    }
}

int sum()
{
    int i;
    double sum=0;
    for(i=0; i<len; i++)
    {
        sum+= (table+i)->cgpa;
    }
    return sum;
}

int search(int id)
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

void findMaxCgpa()
{
    double max=(table+0)->cgpa;
    int flag;
    for(int i=0; i<len; i++)
    {
        if((table+i)->cgpa>max) {flag=i;}
    }
    printf("\n\nHighest CGPA Student's Name = %s || Age = %d || CGPA = %lf\n\n",(table+flag)->name,(table+flag)->age,(table+flag)->cgpa);
}

void findMinCgpa()
{
    double min=(table+0)->cgpa;
    int flag;
    for(int i=0; i<len; i++)
    {
        if((table+i)->cgpa<min) {flag=i;}
    }
    printf("\n\nLowest CGPA Student's Name = %s || Age = %d || CGPA = %lf\n\n",(table+flag)->name,(table+flag)->age,(table+flag)->cgpa);
}

void sortTabCgpa()
{
    double *CTable[len],*temp;
    for(int i=0; i<len; i++)
    {
        CTable[i]=&(table+i)->cgpa;
    }
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(*CTable[j]<*CTable[i])
            {
                temp=CTable[i];
                CTable[i]=CTable[j];
                CTable[j]=temp;
            }
        }
    }
    printf("\n                Student Sorted Table By CGPA");
    printf("\n-----------------------------------------------------------------\n");
    printf("     ID       Name                   Age           CGPA\n");
    printf("    ----     ------                 -----        --------\n\n");
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(*CTable[i]==(table+j)->cgpa) {print(j);}
        }
    }
}

void sortTabAge()
{
    int *CTable[len],*temp;
    for(int i=0; i<len; i++)
    {
        CTable[i]=&(table+i)->age;
    }
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(*CTable[j]<*CTable[i])
            {
                temp=CTable[i];
                CTable[i]=CTable[j];
                CTable[j]=temp;
            }
        }
    }
    printf("\n                Student Sorted Table By CGPA");
    printf("\n-----------------------------------------------------------------\n");
    printf("     ID       Name                   Age           CGPA\n");
    printf("    ----     ------                 -----        --------\n\n");
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(*CTable[i]==(table+j)->age) {print(j);}
        }
    }
}

int removeStd(int pos)
{

    for(int i=pos,j=pos+1; i<len; i++,j++)
    {
        (table+i)->id=(table+j)->id;
        strcpy((table+i)->name,(table+j)->name);
        (table+i)->age=(table+j)->age;
        (table+i)->cgpa=(table+j)->cgpa;
    }
    len--;
    if(len<mem/2)
        {table=(struct info*)realloc(table,mem/2*sizeof(struct info));}
    return 1;

}

int main()
{
        int choice;

        while(1){

                printf("\n----------------------------\n");
                printf("        Table Menu\n");
                printf("----------------------------\n");
                printf(" 1 : Insert Data\n");
                printf(" 2 : Print table\n");
                printf(" 3 : Sum of Students CGPA\n");
                printf(" 4 : Average CGPA of Student\n");
                printf(" 5 : Search Student By ID\n");
                printf(" 6 : Print Maximum CGPA Student's Data\n");
                printf(" 7 : Print Minimum CGPA Student's Data\n");
                printf(" 8 : Sort Table By CGPA\n");
                printf(" 9 : Sort Table by Age\n");
                printf(" 10: Remove Student\n");
                printf(" 11 : Exit\n");
                printf("\n--------------------------------------\n");
                printf("Now Tell Me What Do You Desire:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                       insert();
                                       break;
                        case 2:
                                    if(table!=NULL)
                                       {
                                         printf("\n                          Student Table\n");
                                         printf("-----------------------------------------------------------------\n\n");
                                         printTable();
                                       }
                                       else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                       break;
                        case 3:
                                    if(table!=NULL)
                                        {
                                         int total=sum();
                                         printf("The Sum of the CGPA is %d\n",total);
                                        }
                                        else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                        break;
                        case 4:
                                    if(table!=NULL)
                                        {
                                         double avg;
                                         double total=sum();
                                         avg=(total)/len;
                                         printf("len=%d\n",len);
                                         printf("\n\nAverage of Students CGPA is = %lf\n\n",avg);
                                        }
                                        else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                        break;
                        case 5:
                                    if(table!=NULL)
                                        {
                                         int id;
                                         printf("Enter Student Id:  ");
                                         scanf("%d",&id);

                                         int found=search(id);
                                         if(found==-1)
                                           {
                                             printf(" Did not find the Student\n");
                                           }
                                         else
                                           {
                                             printf("\n\nID Found.\nName=%s || Age=%d || CGPA=%lf\n\n",(table+found)->name,(table+found)->age,(table+found)->cgpa);
                                           }
                                         }
                                    else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                       break;
                        case 6:
                                        if(table!=NULL){ findMaxCgpa();}
                                        else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                        break;
                        case 7:
                                        if(table!=NULL){ findMinCgpa();}
                                        else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                        break;
                        case 8:
                                        if(table!=NULL){ sortTabCgpa();}
                                        else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                        break;
                        case 9:
                                        if(table!=NULL){ sortTabAge();}
                                        else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}
                                        break;
                        case 10:
                                    if(table!=NULL)
                                     {
                                       int id;
                                       printf("\n\nEnter the Id of the Student: ");
                                       scanf("%d",&id);
                                       int found=search(id);
                                       if(found==-1)
                                        {
                                          printf(" Did not find the Student\n");
                                        }
                                       else
                                        {
                                          int deleted=removeStd(found);
                                          if(deleted==1)
                                            {
                                               printf("\n\nStudent Removed Successfully!\n\n");
                                            }
                                          else
                                            {
                                              printf("\n\nSomething is Wrong!\n\n");
                                            }
                                        }
                                      }
                                    else {printf("\nThere are No Data in the Table. Please Insert Data First.\n");}

                                    break;

                        case 11:
                                        exit(0);
                                        break;

                        default:
                                        printf("\nYou Have A Wrong Desire\n");
                                        break;
                }
        }
        return 0;
}
