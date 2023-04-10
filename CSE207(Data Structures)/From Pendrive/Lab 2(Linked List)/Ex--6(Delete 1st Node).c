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
void delete_beg(struct Node *s)
{
    struct Node *p;
    p=s->next;
    s->next=s->next->next;
    free(p);
}
int main()
{
    int x,n,a;
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
    delete_beg(head);
    display(head);
}
