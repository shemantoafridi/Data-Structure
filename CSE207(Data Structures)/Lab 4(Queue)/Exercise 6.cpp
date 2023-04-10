#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*node;

struct head
{
    int c;
    struct node *frnt;
    struct node *rear;
}*head;

void instruct_Head()
{
    head =(struct head*) malloc (sizeof(struct head));
    head->c=0;
    head->frnt=NULL;
    head->rear=NULL;
}

void instruct_Node()
{
    node =(struct node*) malloc (sizeof(struct node));
    node->next=NULL;
}

void enqueue(int data)
{
    instruct_Node();
    node->data=data;

    if(head->c==0)
    {
        head->frnt=node;
        head->rear=node;
    }
    else
    {
        head->rear->next=node;
        head->rear=node;
    }

    head->c++;
}

void dequeue(struct node *s)
{
    struct node *p;

    p=s->next;
    s->next=p->next;
    free(p);
    s=s->next;
    head->c--;
}

void delete_Neg()
{
    struct node *s;

    s=head->frnt;

    while(s->next!=NULL)
    {
        if(s->next->data<0)
        {
            dequeue(s);
        }
        else
        {
            s=s->next;

        }

    }
}

void display()
{
    struct node *s;
    s=head->frnt;

    while(s != NULL)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
}

int main()
{
    instruct_Head();
    enqueue(6);
    enqueue(5);
    enqueue(-3);
    enqueue(8);
    enqueue(-7);
    enqueue(4);
    cout<<" Enqueuing data:\n ";
    display();
    cout<<endl;
    cout<<"Deleted negative integer : ";
    delete_Neg();
    display();
    cout<<endl;
    return 0;
}
