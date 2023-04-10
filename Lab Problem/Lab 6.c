#include<stdio.h>
#include<stdlib.h>
struct Node* creat(struct Node *node,int data);
void In(struct Node *s);
void Pre(struct Node *t);
void Post(struct Node *u);
struct Node* search(struct Node *node,int data);
struct Node* Min(struct Node *node);
struct Node* Max(struct Node *node);
struct Node* Delete(struct Node *node,int data);
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int main()
{
    struct Node *root=NULL,*temp;
    int choice;
    while(1)
    {
        printf("\n\n                  Menu");
        printf("\n\n 1.Insert");
        printf("\n 2.Display In-Order");
        printf("\n 3.Display Pre-Order");
        printf("\n 4.Display Post-Order");
        printf("\n 5.Search");
        printf("\n 6.Find Minimum");
        printf("\n 7.Find Maximum");
        printf("\n 8.Delete");
        printf("\n 9.Exit");
        printf("\n----------------------------");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int value;
            printf("Enter the value to Insert: ");
            scanf("%d",&value);
            root=creat(root,value);
        }
        if(choice==2)
        {
            In(root);
        }
        if(choice==3)
        {
            Pre(root);
        }
        if(choice==4)
        {
            Post(root);
        }
        if(choice==5)
        {
            printf("Enter the data to Search: ");
            int data;
            scanf("%d",&data);
            temp=search(root,data);
            if(temp!=NULL){ printf("Value Not Found\n");}
            else {printf("Value Found\n");}
        }
        if(choice==6)
        {
            temp=Min(root);
            printf("Minimum Value is: %d\n",temp->data);
        }
        if(choice==7)
        {
            temp=Max(root);
            printf("Maximum Value is: %d\n",temp->data);
        }
        if (choice==8)
        {
            int data;
            printf("Input Data to Delete: ");
            scanf("%d",&data);
            root=Delete(root,data);
        }
        if(choice==9)
        {
            exit(0);
        }
    }

}
struct Node* creat(struct Node *node,int data)
{
    if(node==NULL)
    {
        struct Node *p;
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    else if(data<(node->data)) {node->left=creat(node->left,data);}
    else {node->right=creat(node->right,data);}

    return node;
}
void In(struct Node *s)
{
    if(s==NULL){ return;}
    else
    {
        In(s->left);
        printf("%d ",s->data);
{
        In(s->right);
    }
}
}
void Pre(struct Node *t)
{
    if(t==NULL){ return;}
    else
    {
        printf("%d ",t->data);
        In(t->left);
        In(t->right);
    }
}
void Post(struct Node *u)
{
    if(u==NULL){ return;}
    else
    {
        In(u->left);
        In(u->right);
        printf("%d ",u->data);
    }
}
struct Node* search(struct Node *node,int data)
{
    if(node==NULL) {return NULL;}
    if(data<node->data) {return search(node->left,data);}
    else if(data>node->data) {return search(node->right,data);}
    else {return node;}
}
struct Node* Min(struct Node *node)
{
    if(node==NULL) {return NULL;}
    if(node->left) {return Min(node->left);}
    else {return node;}
}
struct Node* Max(struct Node *node)
{
    if(node==NULL) return NULL;
    if(node->right) return Max(node->right);
    else return node;
}
struct Node* Delete(struct Node *node,int data)
{
    struct Node *tem;
    if(node==NULL){ printf("This Value not Found");}
    else if(data<node->data) {node->left= Delete(node->left,data);}
    else if(data>node->data){ node->right= Delete(node->right,data);}
    else
    {
        if(node->left&&node->right)
        {
            tem=Min(node->right);
            node->data=tem->data;
            node->right=Delete(node->right,tem->data);
        }
        else
        {
            tem=node;
            if(node->left==NULL) node=node->right;
            else if(node->right==NULL) node=node->left;
            free(tem);
        }
    }
    return node;
}
