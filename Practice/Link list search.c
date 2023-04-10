#include<stdio.h>
#include<stdlib.h>
void creat(int arr[],int num);
void dis();
int srch(int val);
struct Node{
int data;
struct Node *next;
}*a;
int main(){
int ar[100],n,v,in=0;

printf("Enter Number Of Element : ");
scanf("%d",&n);
printf("\n");
for(int i=0;i<n;i++){
    printf("Enter Element: ");
    scanf("%d",&ar[i]);
}
creat(ar,n);
printf("\n");
printf("Enter Search Element : ");
scanf("%d",&v);
printf("Link List : ");
dis();
in=srch(v);
printf("\nIndex : %d , Value : %d",in , v);
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
int srch(int val){
int count=1;

while(a!= NULL){
    if(a->data==val){
       return count;
    }
    count++;
    a=a->next;}
}

void dis(){


while(a!= NULL){
    printf("%d -> ",a->data);

    a=a->next;
}
printf("NULL");
}

