#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*node,*temp,*temp1;

struct Head
{
    struct Node *p,*s;
}*head;
void instruct_Head()
{
    head =(struct Head*)malloc(sizeof(struct Head));
    head->p=NULL;
    head->s=NULL;

}
void instruct_Node()
{
        int a;
        node = (struct Node*)malloc(sizeof(struct Node));
        cout<<"push node:"<<endl;
        cin>>a;
        node->data=a;
        node->next=head->s;
        node->next=head->p;
        head->s=node;
        head->p=node;
        node->next=NULL;

}
void Enqueue()
{
        int b;
        node=(struct Node*)malloc(sizeof(struct Node));
        cout<<"push node:"<<endl;
        cin>>b;
        node->data=b;
        node->next=head->p;
        head->p=node;
}
void Dequeue()
{
    for(temp=head->p ;  ; temp=temp->next)
    {
        if(temp->next->next==NULL)
        {
            temp1=temp->next ;
            temp->next=temp1->next ;
            free(temp1) ;
            break ;
        }
    }
}

void print()
{
    temp=head->p;
    while(temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
  //  printf("\n");
}

int main()
{
    int x,n;
    instruct_Head();
   for(; ;)
   {
      printf("\nTo Enqueue data press 1\nTo Dequeue data press 2\nTo print data press 3,\nTo go out from loop press 4\n");
      cin>>x;

      if(x==1)
      {
          cout <<"how many nodes:"<<endl;
          cin>>n;
       for(int i=0;i<n;i++)
       {
        if(i==0)
        {
            instruct_Node();
        }
        else
        {
            Enqueue();
        }
      }
    }

    if(x==2)
    {
    Dequeue();

    }
    if(x==3)
    {
    print();
    }
    if(x==4)
    {
        break;
    }
}
return 0;
}

