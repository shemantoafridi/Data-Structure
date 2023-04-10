#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct emp
{
        char name[40];
        int age,salary;
        float workProg;
        char d[10];
        char workType;
};
struct emp e;
struct authority
{
    char name[40];
    int age,salary;
};
struct authority a;
struct workList
{
    char name[40];

};
struct workList w;
int main()
{
int n;
printf("How many works there are : ");
scanf("%d",&n);
for(int k=0;k<n;k++){
    printf("Name of work types: ");
    scanf("%s",w.name);
}
struct emp p[20];
for(int i=0;i<2;i++)
{
    printf("\nEnter Name : ");
    scanf("%s",p[i].name);
    printf("\nEnter Age : ");
    scanf("%d",&p[i].age);
    printf("\nEnter Salary : ");
    scanf("%d",&p[i].salary);
    printf("\nEnter Work Type : ");
    scanf("%s",&p[i].workType);
    printf("\nEnter Work Progress : ");
    scanf("%f",&p[i].workProg);
    printf("\nDone or Undone : ");
    scanf("%s",&p[i].d);
}
struct authority au[5];
printf("Authority List : ");
for (int i=0;i<5;i++)
{
    printf("Enter Name : ");
    scanf("%s",p[i].name);
    printf("Enter Age : ");
    scanf("%d",p[i].age);
    printf("Enter Salary : ");
    scanf("%d",p[i].salary);
}
}

