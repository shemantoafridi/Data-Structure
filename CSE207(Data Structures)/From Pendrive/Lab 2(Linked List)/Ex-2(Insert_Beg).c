#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
void insert_Beg(struct Node *s, int data)
{
    struct Node *p;
    if(s->link==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->link=NULL;
        s->link=p;
    }
    else
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->link=s->link;
        s->link=p;
    }
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
    int x,n;
    struct Node *head;
    printf("Number of Nodes = ");
    scanf("%d",&n);

    head = (struct Node*)malloc(sizeof(struct Node));
    head->link=NULL;
    for(int i=0;i<n;i++)
    {
        printf("The Node = ");
        scanf("%d",&x);
        insert_Beg(head,x);
    }
    print_list(head);
}
