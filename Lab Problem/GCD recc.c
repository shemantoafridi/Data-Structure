#include<stdio.h>

int GCD(int x ,int y);
int main()
{
    int a,b;
    printf("Enter the first number = ");
    scanf("%d",&a);
    printf("Enter the second number = ");
    scanf("%d",&b);
    printf("GCD of the numbers = %d ",GCD(a,b));

    return 0;
}

int GCD(int x ,int y)
{
    if(x==0)
    {
        return y;
    }
    else if(y==0)
    {
        return x;
    }
    else
    {
       return GCD(y,x%y);
    }
}
