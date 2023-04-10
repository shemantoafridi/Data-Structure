#include<stdio.h>
int frt = -1,rer = -1;
int q[50];
void enq(int data,int l)
{
	if(rer==l-1){
		printf("Queue is full");
	}
	else if((frt==-1)&&(rer==-1)){
		frt = rer = 0;
		q[rer] = data;
	}
	else
	{
		rer++;
		q[rer] = data;
	}
}
void print()
{
	int i;
	for(i=frt;i<=rer;i++)
	{
		printf("%d ",q[i]);
	}
}
void rev()
{
	int i,j,temp;
	for(i=frt,j=rer;i<j;i++,j--){
		temp = q[i];
		q[i] = q[j];
		q[j] = temp;
	}
}
void main()
{
	int n,i=0,temp;
	printf("Size of Queue:");
	scanf("%d",&n);
	printf("\nEnter the data for Queue: ");
	while(i<n){
		scanf("%d",&temp);
		enq(temp,n);
		i++;
	}
	printf("\nQueue before reverse : ");
	print();
	rev();
	printf("\nQueue after reverse  : ");
	print();

}
