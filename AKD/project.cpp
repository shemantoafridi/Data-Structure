#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char name[100];
	int train_num;
	int num_of_seats;
}node;




void showtraindetails()
{
	system("cls");
	printf("\n");
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("\n");
	printf("\n1\tShonar Bangla Express\tDhaka to Chittagong\tRs.800 taka \t\t 7 am");
	printf("\n2\tPadma Express\tDhaka To Rajshahi\t 500 taka \t\t 11 pm");
	printf("\n3\tParabat Express\tDhaka To Sylhet\t 550 taka \t\t 6:30 am");
	printf("\n4\tChitra Express\tDhaka To Khulna\t 650 taka \t\t 8 pm");
	printf("\n5\tPanchagar Express\tDhaka To Panchagar\t 1000 taka \t\t 11:30 pm");
	printf("\n6\tShubarna Express\tDhaka To Chittagong\t 600 taka \t\t 4:30 pm");
    printf("\n7\tBalaka Express\tDhaka To Mymensing\t 150 taka \t\t 1 pm");
}



 void reservation()
{
    int i=0,charges;
	char confirm;
	node passdetails;
	FILE *file;
	file=fopen("Seats_Reserved.txt","a");
	system("cls");

	printf("\nYour Name:");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nNumber of Seats:");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n Press Enter To Show the Details of the Trains: ");
	getch();
	system("cls");
	showtraindetails();
	printf("\n\nInsert Train Number: ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1 && passdetails.train_num<=7)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid  Number. Please Enter Again: ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (yes or no):");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(file,"%s\t\t\t%d\t\t%d\t\t%d\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("\n Reservation Done\n");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Failed\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice . Enter Again: ");
			goto start;
		}
	}
	fclose(file);
	getch();
}


  int charge(int trainnumber,int numberofseats)
{
		if (trainnumber==1)
	{
		return(800.0*numberofseats);
	}
	if (trainnumber==2)
	{
		return(500.0*numberofseats);
	}
	if (trainnumber==3)
	{
		return(550.0*numberofseats);
	}
	if (trainnumber==4)
	{
		return(650.0*numberofseats);
	}
	if (trainnumber==5)
	{
		return(1000.0*numberofseats);
	}
	if (trainnumber==6)
	{
		return(650.0*numberofseats);
	}
	if (trainnumber==7)
	{
		return(150.0*numberofseats);
	}

}

  void printticket(char name[],int numberofseats,int trainnumber,int totalamount)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",numberofseats);
	printf("\nTrain Number:\t\t%d",trainnumber);
	specifictrain(trainnumber);
	printf("\nCharges:\t\t%d  ",totalamount);
}

void specifictrain(int trainnumber)
{

	if (trainnumber==1)
	{
		printf("\nTrain:\t\t\tShonar Bangla  Express");
		printf("\nDestination:\t\tDhaka to Chittagong");
		printf("\nDeparture:\t\t 7 am ");
	}
	if (trainnumber==2)
	{
		printf("\nTrain:\t\t\tPadma Express");
		printf("\nDestination:\t\tDhaka to Rajshahi");
		printf("\nDeparture:\t\t 11 pm");
	}
	if (trainnumber==3)
	{
		printf("\nTrain:\t\t\tParabat  Express");
		printf("\nDestination:\t\tDhaka to Sylhet");
		printf("\nDeparture:\t\t 6:30 am");
	}
	if (trainnumber==4)
	{
		printf("\nTrain:\t\t\tChitra  Express");
		printf("\nDestination:\t\tDhaka to khulna");
		printf("\nDeparture:\t\t 8 pm");
	}
	if (trainnumber==5)
	{
		printf("\nTrain:\t\t\tPanchagar Express");
		printf("\nDestination:\t\tDhaka to Panchagar");
		printf("\nDeparture:\t\t 11:30 pm");
	}
	if (trainnumber==6)
	{
		printf("\ntrain:\t\t\tShubarna Express");
		printf("\nDestination:\t\tDhaka to Chittagong");
		printf("\nDeparture:\t\t 4:30 pm");
	}
	if (trainnumber==7)
	{
		printf("\ntrain:\t\t\tBalaka Express");
		printf("\nDestination:\t\tDhaka to Mymensingh");
		printf("\nDeparture:\t\t 1pm ");
	}

}

   void login()
{
	int a=0,i=0;
    char username[10],ch=' ';
    char password[10],code[10];
    char user[10]="admin";
    char pass[10]="bangla";
    do
{

    printf("\n          LOGIN FORM                      \n  ");
    printf(" \n                       ENTER USERNAME:");
	scanf("%s", &username);
	printf(" \n                       ENTER PASSWORD:");
	while(i<10)
	{
	    password[i]=getch();
	    ch=password[i];
	    if(ch==13) break;

	    else printf("*");
	    i++;
	}
	password[i]='\0';
	i=0;

		if(strcmp(username,"admin")==0 && strcmp(password,"bangla")==0)
	{
	printf("  \n\n\n       WELCOME TO TRAIN RESERVATION SYSTEM");
	printf("\n\n\n\t\t\t\tPress any key to continue");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY .  LOGIN FAILED");
		a++;
		getch();
		system("cls");
	}

}
while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");


}
int main()

{
		system("cls");
	printf("\t\t|        TRAIN TICKET RESERVATION SYSTEM      |\n");

	printf(" \n Press any key to continue:");

	getch();
    system("cls");
	login();
	int menu;
	start:
	system("cls");
	printf("    TRAIN TICKET RESERVATION SYSTEM");
	printf("\n");
	printf("\n2  Reserve A Ticket:");
	printf("\n");
	printf("\n3  Show the Train Details:");
	printf("\n");
	printf("\n5 Exit");
	printf("\n");
	printf("\n");
	printf("Enter Your Option:");
	scanf("%d",&menu);
	switch(menu)
	{
		case 2:
			reservation();
			break;
		case 3:
			showtraindetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 5:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}