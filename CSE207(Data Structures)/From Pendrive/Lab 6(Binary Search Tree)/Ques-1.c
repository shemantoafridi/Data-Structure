#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *right,*left;
};
void struct_Node(struct Node *root,int data)
{
    root =(struct Node*)malloc(sizeof(struct Node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
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
    else
    {
         if(value <root->data)
         {
             root->left=(struct Node*)malloc(sizeof(struct Node));
             root->left->data=value;
             root->left->left=NULL;
             root->left->right=NULL;
         }
        else
         {
             root->right=(struct Node*)malloc(sizeof(struct Node));
             root->right->data=value;
             root->right->left=NULL;
             root->right->right=NULL;
         }
   }
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
