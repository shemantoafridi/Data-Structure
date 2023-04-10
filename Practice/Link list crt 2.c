#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main(){
int n,data;
struct Node *a=NULL ,*b=NULL , *temp=NULL;

printf("Enter Number Of Element: ");
 scanf("%d",&n);

printf("\n");
for(int i=1;i<=n;i++){
    b=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Element: ");
    scanf("%d",&data);

    b->data=data;
    b->next=NULL;

    if(a==NULL){
        a=b;
        temp=b;
    }
    else{
    temp->next=b;
    temp=temp->next;
    }
}
printf("\n");

while(a!= NULL){
    printf("%d -> ",a->data);

    a=a->next;
}
printf("NULL");
}
