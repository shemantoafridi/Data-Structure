#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
void insert_end(struct Node *s,int data)
{
    while(s->link!=NULL)
    {
        s=s->link;
    }
    s->link=(struct Node*)malloc(sizeof(struct Node));
    s->link->data=data;
    s->link->link=NULL;
}
void print_list(struct Node *s)
{
    while(s->link!=NULL)
    {
        printf("%d\n",s->link->data);
        s=s->link;
    }
}
int main()
{
   int x,n,a;
   struct Node *head;
   printf("Number of Nodes = ");
   scanf("%d",&n);

   head = (struct Node*)malloc(sizeof(struct Node));
   head->link=NULL;

   for(int i=0;i<n;i++)
   {
       printf("The Nodes = ");
       scanf("%d",&x);
       insert_end(head,x);
   }
   print_list(head);
}
