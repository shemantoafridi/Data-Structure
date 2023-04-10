#include<stdio.h>

int GCD(int a ,int b)
{
    if(a==0)
    {
        return b;
    }
    else if(b==0)
    {
        return a;
    }
    else
    {
       return GCD(b,a%b);
    }
}
int main()
{
    int x,y;
    printf("Enter the first number = ");
    scanf("%d",&x);
    printf("Enter the second number = ");
    scanf("%d",&y);
    printf("GCD of the numbers = %d ",GCD(x,y));

    return 0;
}
