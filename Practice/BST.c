#include<stdio.h>
#include<stdlib.h>
void creat(int num);
void dis();
struct Node{
int data;
struct Node *left;
struct Node *right;
}*p=NULL,*q=NULL,*root=NULL;

int main(){
int n;

printf("Enter Number Of Element : ");
scanf("%d",&n);
printf("\n");
root=creat(root,n);
printf("\n");
printf("Link List : ");
dis();
}
struct node* creat(struct Node *node,int num){
int data;

for(int i=1;i<=num;i++){
    p=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Element: ");
    scanf("%d",&data);
 if(node==NULL)
    {
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    else if(data<(node->data)){node->left=creat(node->left,data);}
    else{node->right=creat(node->right,data);}

    return node;
    }
}
/*void dis(){


while(q!= NULL){
    printf("%d -> ",q->data);

    q=q->left;
    q=q->right;
}

printf("NULL");
}*/
