#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CAP 6
struct Node{
int data;
struct Node *next;
}*front=NULL,*rear=NULL;
void ins(int value);
void del();
void print();
int main(){
     int choice, value;
    while(1)
    {

        printf(" \n 1. Insert\n 2. Delete\n 3. Display\n 4. Insert Again\n 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            ins(value);
            break;
        case 2:
            del();
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
              ins(value);
            break;
        case 5:
            exit(0);
        }

}
}
void ins(int value){
struct Node *temp;

for(int i=1;i<=CAP;i++){
    temp=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&value);
    temp->data=value;
    temp->next=NULL;

   if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
    rear->next=temp;
    rear=rear->next;
    }
    }

}
void del(){
    if(front==NULL){
        printf("Queue Is Empty.\n");
    }
    else{
    struct Node *tmp;
    tmp=front;
    front=front->next;
    tmp->data;
    free(tmp);}
}
void print(){
    if(front==NULL){
        printf("Queue Is Empty.\n");
    }
    else{
while(front!= NULL){
    printf("%d -> ",front->data);

    front=front->next;
}
printf("NULL");
printf("\n");}
}
