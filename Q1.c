//EXAMPLE EDIT ON FIRST LINE
#include <stdio.h>
struct inventory{
	char tool[100]; //Tool Name
	int quantity; 
	float cost;
};
void fourth(void)
{
	int j,rec,k;
	FILE *f;
	struct inventory ok[100];
	system("cls");
	f=fopen("hardware.dat","rb+");
	if(f==NULL)
	{printf("Problems in opening the File!");
	ExitProcess(0);} //Ends the Program and Closes it
	fread(&ok,sizeof(ok),1,f); 
	rewind(f);
	again:
	printf("\nPlease Enter record number you would like to Update information of: ");
	scanf("%d", &rec);
	if(ok[rec-1].quantity!=0&&ok[rec-1].cost!=0)
	{printf("Following record is being Updated.\n%-12s %-8s %-4s\n%-12s %-8d %-8.2f\n\nAre You Sure? (1 for Yes / 2 For No)  ","Name","Quantity","Cost",ok[rec-1].tool,ok[rec-1].quantity,ok[rec-1].cost);
	scanf("%d", &j);
	if(j==1)
	{
		printf("\nPlease Input Name of tool:  ");
		fflush(stdin);
		scanf("%[^\n]s", ok[rec-1].tool);
		printf("\nPlease Input Quantity of tool: ");
		scanf("%d", &ok[rec-1].quantity);
		printf("\nPlease Input Cost of tool: ");
		scanf("%f", &ok[rec-1].cost);
		printf("\nNew record added as follows:\n%-12s %-8s %-4s\n%-12s %-8d %-8.2f","Name","Quantity","Cost",ok[rec-1].tool,ok[rec-1].quantity,ok[rec-1].cost);
		fwrite(&ok,sizeof(ok),1,f);
		rewind(f);
	}
	else
	{printf("Back to record Input: \n");
	goto again;}
	}
	else
	{
		printf("\nNo such reocrd exists. Would You like to Try another record number? (1 for Yes / 2 For No)  ");
		scanf("%d", &k);
		if(k==1)
		{
		goto again;	
		}
		if(k==2)
		{
			return;
		}
	}	
		
}
void third(void)
{
	int j,rec,k;
	FILE *f;
	struct inventory ok[100];
	system("cls");
	f=fopen("hardware.dat","rb+");
	if(f==NULL)
	{printf("Problems in opening the File!");
	ExitProcess(0);}
	fread(&ok,sizeof(ok),1,f);
	rewind(f);
	again:
	printf("\nPlease Enter record number you would like to Delete information of: ");
	scanf("%d", &rec);
	if(ok[rec-1].quantity!=0&&ok[rec-1].cost!=0)
	{printf("Following record will be deleted.\n%-12s %-8s %-4s\n%-12s %-8d %-8.2f\n\nAre You Sure? (1 for Yes / 2 For No) ","Name","Quantity","Cost",ok[rec-1].tool,ok[rec-1].quantity,ok[rec-1].cost);
	scanf("%d", &j);
	if(j==1)
	{
		ok[rec-1].cost=0;
		ok[rec-1].quantity=0;
		strcpy(ok[rec-1].tool,"");
		printf("\nRecord Deleted!\n");
		sleep(1);
		fwrite(&ok,sizeof(ok),1,f);
		rewind(f);
	}
	else
	{printf("Back to record Input:\n");
	goto again;}
	}
	else
	{
		printf("\nNo such reocrd exists. Would You like to Try another record number? (1 for Yes / 2 For No)  ");
		scanf("%d", &k);
		if(k==1)
		{
		goto again;	
		}
	}
	fclose(f);	
}
void second(void)
{
	int j;
	FILE *f;
	struct inventory ok[100];
	f=fopen("hardware.dat","rb"); //Opened as read only file
	if(f==NULL)
	{printf("Problems in opening the File!");
	ExitProcess(0);}
	fread(&ok,sizeof(ok),1,f);
	rewind(f);
	for(j=0;j<100;j++)
	{
		if(j==0)
		{printf("All Tools and Their Information is as Follows:\n%-9s %-12s %-8s  %-4s","Record#","Name","Quantity","Cost");}
		if(ok[j].cost!=0 && ok[j].quantity!=0)
		{
		printf("\n%-9d %-12s %-8d  %-8.2f",j+1,ok[j].tool,ok[j].quantity,ok[j].cost);	
		}
	}
	fclose(f);
	
}
void first(void)
{	
	int rec,ch;
	FILE *f;
	struct inventory ok[100];
	f=fopen("hardware.dat","rb+"); //Opens file in read and write mode
	if(f==NULL)
	{printf("Problems in opening the File!");
	ExitProcess(0);}
	fread(&ok,sizeof(ok),1,f);
	rewind(f);
	                    //resets file pointer position to start of file
	first:
	system("cls");
	printf("Please Enter record number you would like to Input information of: ");
	scanf("%d", &rec);
	if(ok[rec-1].quantity==0&&ok[rec-1].cost==0)
	{printf("\nPlease Input Name of New tool:");
	fflush(stdin);
	scanf("%[^\n]s", ok[rec-1].tool);
	printf("\nPlease Input Quantity of New tool: ");
	scanf("%d", &ok[rec-1].quantity);
	printf("\nPlease Input Cost of New tool: ");
	scanf("%f", &ok[rec-1].cost);
	printf("\nNew record added as follows:\n%-9s %-12s %-8s %-4s\n%-9d %-12s %-8d  %-8.2f\n","Record#","Name","Quantity","Cost",rec,ok[rec-1].tool,ok[rec-1].quantity,ok[rec-1].cost);
	fwrite(&ok,sizeof(ok),1,f);
	rewind(f);}
	else
	{printf("\n\nInformation for Record Number %d already exists. If you want to update record, Go to main menu and choose Option 4.\n", rec);}
	printf("\nWould you like to Enter Another record?\n(1 for Another record / 2 for No)  ");
	scanf("%d", &ch);
	if(ch==1)
	{system("cls"); //Clears screen
	goto first;}
	else if(ch==2)
	{system("cls");
	fclose(f);
	}
}

int main()
{
	int i,j,k,num,rec,ch;
	struct inventory ok[100];
	FILE *f;
	
		f=fopen("hardware.dat","wb+"); //read and write mode but file is emptied every time it is opened
		if(f==NULL)
		{printf("Problems in opening the File!");
		ExitProcess(0);}
		for(i=0;i<100;i++)
		{
			strcpy(ok[i].tool,"");
			ok[i].quantity=0;					//code used to initialize file with 100 empty structures. Comment out line 170-181 to make sure data stays intact.
			ok[i].cost=0;
		}
		fwrite(&ok,sizeof(ok),1,f);
		fclose(f);
	
	start:
	printf("Program Options:\n\n1) Input information about new tools\n\n2) List all tools\n\n3) Delete information of a tool\n\n4) Update information of existing tool\n\n5) Close Program\n\nWhich Operation would you like to perform? ");
	scanf("%d", &num);
	if(num==1)
	{
		first();
		system("cls");
		goto start;
	}
	else if(num==2)
	{
		system("cls");
		second();
		printf("\n\nPress Any key to go back to main menu");
		getch();
		system("cls");
		goto start;

	}
	else if(num==3)
	{
		system("cls");
		third();
		system("cls");
		goto start;
		
	}
	else if(num==4)
	{
		system("cls");
		fourth();
		system("cls");
		goto start;	
	}
	else if(num==5)
	{
		return 0;
	}
	else
	{system("cls");
	printf("\nIncorrect Number Given! Please Give Input again\n\n");
	goto start;
	}
	
}
