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

void search(struct Node *s,int search)
{
    int count=0;
    while(s->next!=NULL)
    {
        if(s->next->data==search)
        {
            count ++;
        }
        s=s->next;
    }
     printf("Total %d results found \n",count);
}
void display(struct Node *s)
{
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
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
    printf("Input the value you want to search = ");
    scanf("%d",&a);
    search(head,a);
    display(head);
}
