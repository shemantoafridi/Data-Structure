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
void insert_Anypos(struct Node *s,int data,int pos)
{
    struct Node *p;
    struct Node *prevnode;
    for(int i=0;i<pos-2;i++)
    {
        if(i==pos-2)
        {
            p=(struct Node*)malloc(sizeof(struct Node));
            p->data=data;
            p->link=s->link;
            prevnode=p;
            p=p->link;

            //s->link=p;
        }
        else
        {
            s=s->link;
        }
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
    int x,n,pos;
    struct Node *head;
    printf("Number of Nodes = ");
    scanf("%d",&n);


    head = (struct Node*)malloc(sizeof(struct Node));
    head->link=NULL;
    for(int i=0;i<n;i++)
    {
        printf("The Nodes value = ");
        scanf("%d",&x);
        void insert_end(head,x);
    }
    printf("Enter the position = ");
    scanf("%d",&pos);
    insert_Anypos(head,3,pos);
    print_list(head);
}

