#include<stdio.h>
#include<stdlib.h>
void creat(int arr[],int num);
void dis();
struct Node{
int data;
struct Node *next;
}*a;
int main(){
int a[100],n;

printf("Enter Number Of Element : ");
scanf("%d",&n);
printf("\n");
for(int i=0;i<n;i++){
    printf("Enter Element: ");
    scanf("%d",&a[i]);
}
creat(a,n);
printf("\n");
printf("Link List : ");
dis();
}
void creat(int arr[],int num){
struct Node *b=NULL , *temp=NULL;

for(int i=0;i<num;i++){
    b=(struct Node*)malloc(sizeof(struct Node));
    b->data=arr[i];
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
