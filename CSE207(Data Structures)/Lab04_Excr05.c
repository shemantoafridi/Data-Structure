#include <stdio.h>
#define MAX 50
char q[MAX],f=-1,r=-1;
char deq()
{
    char val;
    if(f == -1)
        printf("No input here");
    else
    {
        val = q[f];
        if(f == r)
            f=r=-1;
        else
            f=f+1;
    }
    return val;
}
void enq(char val)
{
    if(r == MAX-1)
        printf("queue is full !!");
    else if(f == -1 && r == -1)
        f=r=0;
    else
        r=r+1;
    q[r]=val;
}
int main()
{
    int i;
    char s[MAX];
    gets(s);
    for(i=0; s[i]!=NULL; i++)
    {
        if(s[i] != ' ')
            enq(s[i]);
    }
    for(i= f; i<=r; i++)
        s[i]=deq();
    s[i]='\0';
    puts(s);

}

