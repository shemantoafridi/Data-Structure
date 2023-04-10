#include<stdio.h>

int gcd(int a,int b)
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
        return gcd(b,a%b);
    }
}
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int x,y;
    printf("Enter the first number = ");
    scanf("%d",&x);
    printf("Enter the second number = ");
    scanf("%d",&y);
    printf("LCM of the two numbers = %d ",lcm(x,y));
    return 0;
}
