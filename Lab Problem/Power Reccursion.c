#include<stdio.h>

int pow(int c ,int d);
int main()
{
    int a,b,res;
    printf("Enter The Base: ");
    scanf("%d",&a);
    printf("Enter The Power: ");
    scanf("%d",&b);
    res=pow(a,b);
    printf("Answer: %d",res);

}

int pow(int c ,int d)
{
    if(d == 0)
    {
        return 1;
    }
    else
    {
        return c*(pow(c,d-1));
    }
    }
