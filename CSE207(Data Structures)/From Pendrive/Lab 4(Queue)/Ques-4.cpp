#include <stdio.h>
#define M 5
int Q1[M],Q2[M],p1=-1,s1=-1,p2=-1,s2=-1;
void enqueue(int Q[],int *p,int *s,int value)
{
    if(*s == M-1)
        printf("Queue is full cannot insert");
    else if(*p == -1 && *s == -1)
        *p=*s=0;
    else
        *s=*s+1;
    Q[*s]=value;
}
void display(int Q[],int *p, int *s)
{
    int i;
    if(*p == -1)
        printf("Queue is empty ");
    else
    {
    for(i=*p;i<=*s;i++)
      printf("%d\n",Q[i]);
    }
}

int main()
{
    int i,value;
    for(i=0;i<M;i++)
    {
        printf("Enter a value :\n");
        scanf("%d",&value);
        enqueue(Q1,&p1,&s1,value);
    }
    printf("Values in queue 1 are :\n");
    display(Q1,&p1,&s1);

    for(i=p1;i<=s1;i++)
                    enqueue(Q2,&p2,&s2,Q1[i]);
    printf("Values in queue 2 are :\n");
    display(Q2,&p2,&s2);

}
