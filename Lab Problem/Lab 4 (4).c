#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5
int Queue1[MAX],Queue2[MAX];
int j=-1,k=-1,x=-1,y=-1;

void display(int Queue[],int *frt, int *rer)
{
    int i;
    if(*frt == -1)
        printf("queue is empty ");
    else
    {
        for(i=*frt; i<=*rer; i++)
            printf("%d\t",Queue[i]);
    }
}
void enq(int Queue[],int *frt,int *rer,int val)
{
    if(*rer == MAX-1)
        printf("Queue is Full");
    else if(*frt == -1 && *rer == -1)
        *frt=*rer=0;
    else
        *rer=*rer+1;
    Queue[*rer]=val;
}
int main()
{
    int i,val;
     printf("Enter value :\n");
    for(i=0; i<MAX; i++)
    {

        scanf("%d",&val);
        enq(Queue1,&j,&k,val);
    }
    printf("\n1st queue :");
    display(Queue1,&j,&k);

    for(i=j; i<=k; i++)
        enq(Queue2,&x,&y,Queue1[i]);
    printf("\n2nd queue :");
    display(Queue2,&x,&y);

}
