#include<stdio.h>
int arr[100],n;
void ins(int num , int tem);
void dis();

int main(){
int ch,num,n=0;
while(1){
    printf("1.Insert.\n");
    printf("2.Display.\n");
    printf("3.Exit.\n");
    printf("What Do You Desire: ");
    scanf("%d",&ch);
    switch(ch){
     case 1:
           printf("Enter The Number: ");
           scanf("%d",&num);
           ins(num,n);
           n=n+1;
           break;
     case 2:
        dis();
        break;
     case 3:
        exit(0);
        break;
     default:
        printf("Wrong Desire.");
    }
}
}
void ins(int num , int tem){
int p;
while(tem>0){
    p=(tem-1)/2;
    if(num<arr[p]){
        arr[tem]=num;
    }
    arr[tem]=arr[p];
    tem=p;
}
arr[0]=num;
}
void dis(){
if(n==0){
    printf("Empty Heap.\n");
}
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
}
