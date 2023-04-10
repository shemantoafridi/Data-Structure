#include<stdio.h>
int power(int c,int d)
{
    if(d==0)
    {
        return 1;
    }
    else if(d%2==0)
    {
        return power(c,d/2)*power(c,d/2);
    }
    else
    {
        return c*power(c,d/2)*power(c,d/2);
    }
}
int main()
{
    int a,b;
    printf("Enter the base = ");
    scanf("%d",&a);
    printf("Enter the power = ");
    scanf("%d",&b);
    printf("%d ^ %d = %d",a,b,power(a,b));
    return 0;
}
