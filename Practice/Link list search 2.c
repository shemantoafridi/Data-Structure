#include<stdio.h>
#include<stdlib.h>
void creat(int num);
void dis();
struct Node{
int data;
struct Node *next;
}*a;
int srch(struct Node *a, int val);
int main(){
int n,v,in;

printf("Enter Number Of Element : ");
scanf("%d",&n);
printf("\n");
creat(n);
printf("\n");
printf("Enter Search Element : ");
scanf("%d",&v);
printf("Link List : ");
dis();
in=srch(a,v);
printf("\nIndex : %d , Value : %d",in , v);
}
void creat(int num){
int data;
struct Node *b=NULL , *temp=NULL;

for(int i=1;i<=num;i++){
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
}
int srch(struct Node *a,int val){
int count=1;

while(a!= NULL){
    if(a->data==val){
       return count;
    }
    else{
    count++;
    a=a->next;}
}
return -1;
}
void dis(){


while(a!= NULL){
    printf("%d -> ",a->data);

    a=a->next;
}
printf("NULL");
}
