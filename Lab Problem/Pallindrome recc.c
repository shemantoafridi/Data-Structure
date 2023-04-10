#include<stdio.h>
int rev(int num);
int pal(int num);
int main()
{
  int n , p;
  printf("Enter the number: ");
  scanf("%d" ,&n);
  p = pal(n);

  if(p==1)
  {
     printf("It's Palindrome");
  }
  else
  {
      printf("It's Not Palindrome");
  }
  }
  int pal(int num)
  {
      if(num==rev(num))
      {
          return 1;
      }
      else
      {
          return 0;
      }

  }
 int rev(int num)
 {
     int rem;
     static int sum=0;
     if(num!=0)
     {
         rem=num%10;
         sum=sum*10+rem;
         rev(num/10);
     }
     else
     {
         return sum;
     }
     return sum;
 }


