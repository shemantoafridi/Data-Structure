#include<stdio.h>
int power(int base,int pow)
{
    if(pow==0)
    {
        return 1;
    }
    else if(pow%2==0)
    {
        return power(base,pow/2)*power(base,pow/2);
    }
    else
    {
        return base*power(base,pow/2)*power(base,pow/2);
    }
}
int main()
{
    int a,b;
    printf("Enter the base = ");
    scanf("%d",&a);
    printf("Enter the power = ");
    scanf("%d",&b);
    printf("Power = %d",power(a,b));
    return 0;
}
