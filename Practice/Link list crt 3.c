#include<stdio.h>
#include<stdlib.h>
void creat(int num);
void dis();
struct Node{
int data;
struct Node *next;
}*a;

int main(){
int n;

printf("Enter Number Of Element : ");
scanf("%d",&n);
printf("\n");
creat(n);
printf("\n");
printf("Link List : ");
dis();
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

void dis(){


while(a!= NULL){
    printf("%d -> ",a->data);

    a=a->next;
}
printf("NULL");
}
