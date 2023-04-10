#include <stdio.h>

int *table;int len;
/*init function*/
void init() {
    table=NULL;
    len=0;
}
/*destroy function*/
void arraydestroy(int *b) {
    if(b!=NULL) {free(b);}
}
/*insert function*/
void enter() {
    int num;
    printf(" Give Integer ");
    scanf("%d",&num);
    len++;
    if ( (table=(int*)realloc(table,len*sizeof(int)))==0) {
         printf("ERROR");
    }
    table[len-1]=num;
}

/*print all elements*/
void printall() {
    int x;
    for(x=0;x<len;x++){ printf(" %d\n",table[x]); }
}

/*sum function*/
int sum(){
int i,sum;
for(i=0,sum=0;i<len;i++) { sum+= table[i]; }
return(sum);
}

/*find integer*/
int findnum(int num) {
    int i;
    for(i=0;i<len;i++) { if(table[i]==num) { return(i); } }
    return(-1);
}

/*find max number*/
int greater() {
    int i,max; max=table[0];
    for(i=1;i<len;i++) {
        if (table[i]>max) {max=table[i];}
    }
    return(max);
}

/*find min number*/
int smaller(){
    int i,min; min=table[0];
    for(i=1;i<len;i++) {
        if (table[i]<min) {min=table[i];}
    }
    return(min);
}

/*sorting*/
void auxon2() {
    int *diktes[len],*tmp,j,i;
    for(i=0;i<len;i++) { diktes[i]=&table[i]; }
    for(i=0;i<len;i++) {
        for(j=i+1;j<len;j++) {
            if(*diktes[j]<*diktes[i]) {
                tmp=diktes[i];
                diktes[i]=diktes[j];
                diktes[j]=tmp;
            }
        }
    }
    for(i=0;i<len;i++){ printf("%d : %d\n",i+1,*diktes[i]); }
}

/*delete number*/
int intremove(int num){
    int x;
    x=findnum(num);
    if (x==-1) {return(-1);}
    else {
        table[x]=table[len-1];
        len--;
        table=(int*)realloc(table,len*sizeof(int));
        return(1);
    }
}

int main(int argc,char* argv[]) {
     int out,y,num;
     init();
     do{
   putchar('\n');
      printf(" 0: Exit\n");
      printf(" 1: Insert number\n");
      printf(" 2: Print table\n");
      printf(" 3: Sum of elements\n");
      printf(" 4: Find Number\n");
      printf(" 5: Print max number\n");
      printf(" 6: Print min number\n");
      printf(" 7: Sort table\n");
      printf(" 8: Delete number\n");
      printf(" Choose your option :  ");
      scanf("%d",&y);
      switch (y) {
       case 1 : {
           printf("Insert Numbers to table\n\n");
           enter();
           break;
       }
       case 2 : {
           printf("Print Table\n\n");
           printall();
           break;
       }
       case 3 : {
           out=sum();
           printf(" Sum of all numbers is : %d\n",out);
           break;
       }
       case 4 : {
           printf(" Give number ");
           scanf("%d",&num);
           printf(" The number is  : %d",num);
           out=findnum(num);
           if(out==-1) {printf(" Did not find it\n"); }
           else {
           printf(" Number is at : %d\n",out+1);
           }
           break;
       }
       case 5 :{
           out=greater();
           printf(" Max number is : %d\n",out);
           break;
       }
       case 6 :{
           out=smaller(0,table);
           printf(" Min number is : %d\n",out);
           break;
       }
       case 7 :{
           printf(" Table sorted is \n");
           auxon2();
           break;
       }
       case 8 :{
           printf(" Give number to delete : ");
           scanf("%d",&num);
           out=intremove(num);
           if(out==1) {
               printf("\nNumber %d has been deleted.\n",num);
           }
           else {
               if(out==-1) {
                   printf("\nNumber %d don't exist.\n",num);
               }
               else {
                printf("\nNumber DID NOT deleted %d.\n",num);
               }
           }
           break;
       }
   }
  }
 while(y!=0);
 arraydestroy(table);
 /*system("pause"); for windows*/
 exit(0);
}
