#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *right,*left;
};
void instruct_Node(int data)
{
    struct Node *s =(struct Node*)malloc(sizeof(struct Node));
    s->data=data;
    s->left=NULL;
    s->right=NULL;
    return s;
}
void insert(struct Node *root,int value)
{
    if(root==NULL)
    {
        root=(struct Node*)malloc(sizeof(struct Node));
        root->right=NULL;
        root->left=NULL;
        root->data=value;
    }
    else if(value<root->data)
    {
        insert(root->left,value);
    }
    else
    {
        insert(root->right,value);
    }
    return root;
}
void inorder(struct Node *root)
{
     if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
int main()
{
    int x,n;
    struct Node *root;
    root=(struct Node*)malloc(sizeof(struct Node));
    root=NULL;
    printf("Number of Node =");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Input data =");
        scanf("%d",&x);
        insert(root,x);
    }
    inorder(root);
}

