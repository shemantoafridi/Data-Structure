#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define CAP 6

int que[CAP];
int front=0,rear=-1,total=0;

bool isFull(){
if(total==CAP){
    return true;
}
else{
    return false;
}
}

bool isEmpty(){
if(total==0){
    return true;
}
else{
    return false;
}
}

int enqueue(int item){
if(isFull()){
    printf("It is full\n");
}
else{
    rear=(rear + 1)%CAP;
    que[rear]=item;
    total++;
}
}

int dequeue(){
if(isEmpty()){
    printf("It is empty");
    return -1;
}

    int fitem=que[front];
    que[front]= -1;
    front=(front + 1)%CAP;
    total--;
return fitem;
}

void print(){
    printf("Queue : ");
    for(int i=0; i<CAP; i++){
        printf("%d ", que[i]);
    }
    printf("\n");
}
void rev(){
int i,j,temp;
	for(i=front,j=rear;i<j;i++,j--){
		temp = que[i];
		que[i] = que[j];
		que[j] = temp;
}
}

int main(){
     int choice, value;
    while(1)
    {

        printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Insert Again\n 5. Reverse\n 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
               for(int i=0; i<CAP; i++){
              scanf("%d",&value);
              enqueue(value);
             }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
              enqueue(value);
            break;
       case 5:
            rev();
            break;
        case 6:
            exit(0);
        }

}
}
