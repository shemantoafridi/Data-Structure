#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void instruct(struct Node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(struct Node*)malloc(sizeof(struct Node));
    s->next->data=data;
    s->next->next=NULL;

}
void display(struct Node *s)
{
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
}
void delete_Anypos(struct Node *s,int pos)
{
    struct Node *p;
    struct Node *nextnode;
    int i=1;
    p=s->next;
    while(i<pos-1)
    {
        p=p->next;
        i++;
    }
    nextnode=p->next;
    p->next=nextnode->next;
    free(nextnode);
}
int main()
{
    int x,n,a,pos;
    struct Node *head;
    printf("Number of Nodes = ");
    scanf("%d",&n);
    head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;

    for(int i=0;i<n;i++)
    {
        printf("Enter Nodes value = ");
        scanf("%d",&x);
        instruct(head,x);
    }
    printf("Enter the position you want to delete = ");
    scanf("%d",&pos);
    delete_Anypos(head,pos);
    display(head);
}

