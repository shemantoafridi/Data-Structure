#include<stdio.h>
int LCM(int x ,int y);
int main()
{
    int a,b;
    printf("Enter the first number = ");
    scanf("%d",&a);
    printf("Enter the second number = ");
    scanf("%d",&b);
    printf("LCM of the numbers = %d ",LCM(a,b));

    return 0;
}

int LCM(int x ,int y)
{
    static temp = 1;
    if(temp % x==0 && temp % y==0)
    {
        return temp;
    }

    else
    {
        temp++;
       return LCM(x,y);
       return temp;
    }
}
