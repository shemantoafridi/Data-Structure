#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*node,*temp,*temp1;

struct Head
{
    struct Node *first;
}*head;

void instruct_Head()
{
    head = (struct Head*)malloc(sizeof(struct Head));
    head->first = NULL;

}
void instruct_Node()
{
        int x;
        node = (struct Node*)malloc(sizeof(struct Node));
        printf("Push Node : ");
        scanf("%d",&x);
        node -> data = x;
        node -> next = head->first;
        head -> first= node;
        node -> next = NULL;

}
void push()
{
        int x;
        node = (struct Node*)malloc(sizeof(struct Node));
        printf("Push Node : ");
        scanf("%d",&x);
        node -> data = x;
        node -> next = head->first;
        head -> first = node;
}
int pop()
{
    int x;
    temp = head->first;
    head -> first = temp->next;
    x = temp->data;
    //cout<<"\n"<<x;
    free(temp);
    return x;
}
void push2(int x)
{
        node = (struct Node*)malloc(sizeof(struct Node));
        temp1 = head->first;
        while(temp1->next != NULL)
        {
            temp1=temp1->next;
        }
        node->data=x;
        node->next=temp1->next;
        temp1->next=node;
}
void display()
{
    temp=head->first;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int a,n;
    instruct_Head();
    printf("how many nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
     if(i==0)
     {
        instruct_Node();
     }
     else
     {
       push();
     }
    }
    printf("Input stack\n");
    //cout<<"input stack:"<<endl;
    display();
    printf("after pop operation :\n");
    pop();
    display();

}
