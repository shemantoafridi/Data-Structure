#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 50
char q[MAX],frt=-1,rer=-1;
char deq()
{
    char val;
    if(frt == -1)
        printf("There is no input");
    else
    {
        val = q[frt];
        if(frt == rer)
            frt=rer=-1;
        else
            frt=frt+1;
    }
    return val;
}
void enq(char val)
{
    if(rer == MAX-1)
        printf("queue is full !!");
    else if(frt == -1 && rer == -1)
        frt=rer=0;
    else
        rer=rer+1;
    q[rer]=val;
}
int main()
{
    int i;
    char str[MAX];
    printf("Enter String: ");
    gets(str);
    for(i=0; str[i]!=NULL; i++)
    {
        if(str[i] != ' ')
            enq(str[i]);
    }
    for(i= frt; i<=rer; i++)
        str[i]=deq();
    str[i]='\0';
    printf("\nNew String: ");
    puts(str);

}

