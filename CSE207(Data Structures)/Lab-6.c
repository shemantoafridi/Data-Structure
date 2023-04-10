#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* FindMin(struct node *node)
{
    if(node==NULL) return NULL;
    if(node->left) return FindMin(node->left);
    else return node;
}
struct node* FindMax(struct node *node)
{
    if(node==NULL) return NULL;
    if(node->right) return FindMax(node->right);
    else return node;
}
struct node* Delete(struct node *node,int data)
{
    struct node *temp;
    if(node==NULL) printf("This Value not Found");
    else if(data<node->data) node->left= Delete(node->left,data);
    else if(data>node->data) node->right= Delete(node->right,data);
    else
    {
        if(node->left&&node->right)
        {
            temp=FindMin(node->right);
            node->data=temp->data;
            node->right=Delete(node->right,temp->data);
        }
        else
        {
            temp=node;
            if(node->left==NULL) node=node->right;
            else if(node->right==NULL) node=node->left;
            free(temp);
        }
    }
    return node;
}
struct node* insert(struct node *node,int data)
{
    if(node==NULL)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else if(data<(node->data)) node->left=insert(node->left,data);
    else node->right=insert(node->right,data);

    return node;
}
struct node* find(struct node *node,int data)
{
    if(node==NULL) return NULL;
    if(data<node->data) return find(node->left,data);
    else if(data>node->data) return find(node->right,data);
    else return node;
}
void InOrder(struct node *p)
{
    if(p==NULL) return;
    else
    {
        InOrder(p->left);
        printf("%d ",p->data);
        InOrder(p->right);
    }
}
void PreOrder(struct node *q)
{
    if(q==NULL) return;
    else
    {
        printf("%d ",q->data);
        InOrder(q->left);
        InOrder(q->right);
    }
}
void PostOrder(struct node *r)
{
    if(r==NULL) return;
    else
    {
        InOrder(r->left);
        InOrder(r->right);
        printf("%d ",r->data);
    }
}
int main()
{
    struct node *root=NULL,*temp;
    int choice;
    while(1)
    {
        printf("\n\n                  Menu");
        printf("\n\n 1.Insert");
        printf("\n 2.Display InOrder");
        printf("\n 3.Display PreOrder");
        printf("\n 4.Display PostOrder");
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
            root=insert(root,value);
        }
        if(choice==2)
        {
            InOrder(root);
        }
        if(choice==3)
        {
            PreOrder(root);
        }
        if(choice==4)
        {
            PostOrder(root);
        }
        if(choice==5)
        {
            printf("Enter the data to Find: ");
            int data;
            scanf("%d",&data);
            temp=find(root,data);
            if(temp!=NULL) printf("Value Found\n");
            else printf("Value Not Found\n");
        }
        if(choice==6)
        {
            temp=FindMin(root);
            printf("Minimum Value is: %d\n",temp->data);
        }
        if(choice==7)
        {
            temp=FindMax(root);
            printf("Maximum Value is: %d\n",temp->data);
        }
        if(choice==8)
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

