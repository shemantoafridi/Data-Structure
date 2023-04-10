#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *ptr = NULL, *s = NULL;
void push(int n)
{
    s = (struct Node*)malloc(sizeof(struct Node));
    s->data = n;
    s->next = NULL;
    if (first == NULL)
    {
        first = s;
    }
    else
    {
        s->next = first;
        first = s;
    }
}
int pop()
{
    int x;
    if (first == NULL)
    {
        printf("Underflow\n");
       // cout<<"underflow\n";
    }
    else
    {
        ptr = first;
        first = first->next;
        x = ptr->data;
        free(ptr);
        return(x);
    }
}
int main()
{
    int n, a;
    printf("Input the decimal number : ");
    scanf("%d",&n);
    while (n > 0)
    {
        a = n % 2;
        n = n / 2;
        push(a);
    }
    ptr = first;
    printf("Binary number is : ");
   // cout<<"binary number is:";
    while(1)
    {
        if (first != NULL)
        {
            printf("%d",pop());

        }
	else{
	    break;
    }
    }
    return 0;
}
