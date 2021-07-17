#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

//Declaring  global variables
float total=0.0;
int item_no,quantity;
char name[50];
float rate,amount;

//Declaring and creating a structure named item_details 
struct item_details{
	int item_no;
	char name[25];
	int quantity;
	float rate;
	float amount;
};

//Declaring the functions
void bill();
void add_item();
void display_item();
void search_item();
int check_item_no(int);
int check_item_no_bill(int);

//main function
int main(){
	
	int ch;
	system("color fc");
	
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n\n\t\t\t\t\t\tSTORE MANAGEMENT\t\t\t\t\t\t\t\n\n");
	printf("\n\n\n\t\t\t\t\t  *******  WELCOME  *******\t\t\t\t\t\t\t\n\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	system("\npause");
	
	SetConsoleTitle("Store Management ");
	
	//Getting the choice from the user	
	do{
		printf("\n1.Calculate Bill\n2.Add item\n3.Display items\n4.Searching an item\n5.Exit\n");
		printf("Enter your choice : ");
	    scanf("%d",&ch);
	    
	    switch(ch)
		{
	    	case 1 :
	    		    system("\npause");
	    		    system("cls");
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					//Calling the function named bill
					bill();
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n"); 
			        break;
	    	case 2 :
	    		    system("\npause");
	    		    system("cls");
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					//Calling the function named add_item
					add_item();
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n"); 
			        break;
	    	case 3 : 
	    	        system("\npause");
	    	        system("cls");
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					//Calling the function named display_item
					display_item(); 
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
			        break;
	    	case 4 :
			        system("\npause");
			        system("cls");
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					//Calling the function named search_item
					search_item(); 
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					break;
			case 5 :
			        system("\npause");
			        system("color b0");
					system("cls"); 
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
			        printf("\n\n\n\t\t\t\t\t   *******  Thank you   *******\n\n\n");
			        printf("\n\t\t\t\t\t*******  Have a nice day !!   *******\n\n\n");
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
			        exit(0);    
	    	default :
			        system("\npause");
			        system("color f6"); 
			        system("cls");
			        printf("\n\n\n\t\t\t\t\t   ******* Sorry!!!Invalid choice *******\n\n\n");
			        printf("\n\t\t\t\t\t*******  Please enter valid choice  *******\n\n\n");
			        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
		}
	}while (ch!=0);
	
    return 0;	
}
	
//Called function named bill	
void bill(){
	system("color e0");
	
    FILE *p;
	FILE *q;
	int bill_no,n,i,a,flag=0,item_num,item_quantity;
	int item_no1,quantity1;
    char name1[50],item_name[50];
    float rate1,item_rate,amount,total=0;
	
	printf("Enter the bill number : ");
	scanf("%d",&bill_no);
	
	printf("\nEnter the number of items : ");
	scanf("%d",&n);
	struct item_details item[n];
	
	for (i=0 ; i<n ; i++)
	{
		do{
			printf("Enter item number : ");
	     	scanf("%d",&item[i].item_no);
		    a=check_item_no_bill(item[i].item_no);
	  
			if (a!=0)
		        printf("\n");
			else
			    printf("\nThis item number doesnot exists!\nPlease enter another item_number .\n\n");   
			    
		}while(a==0);
    }
    
	system("pause");
	system("cls");
	
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("\n                              **** Store Management ****                \n");
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("\n                                    ABCD Stores                          \n");
	printf("\n                            18A,Palani Road,Udumalpet                       \n");
	printf("\nBill number : %d\n",bill_no);
	printf("\nDate        : %s\n ",__DATE__);
	printf("\nTIME        : %s\n ",__TIME__);
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("\n_____________________________________________________________________________________\n");
	printf("\nS.no\t\tItem_no\t\tName\t\tQuantity\tRate\t\tAmount\t\t");
	printf("\n_____________________________________________________________________________________\n");
	
	q=fopen("bill.txt","r");
	if(q==NULL)
	    printf("\nThe file doesnot exist\n");

	i=0;
	while((fscanf(q,"%d\t%s\t%d\t%f\t%f",&item_num,item_name,&item_quantity,&item_rate,&amount)) != EOF)
	{
		total += amount;
		printf("\n%d\t\t%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\t", i+1 , item_num , item_name , item_quantity,item_rate ,amount);
		i++;
    }
    fclose(q);
    
    printf("\n_____________________________________________________________________________________\n");
	printf("\n                                          Total Amount                =      %.2f ", total);
	printf("\n_____________________________________________________________________________________\n");
	printf("                                *****   Thank you  *****                                \n");
	printf("                               *****   Visit again  *****                               \n");
	
	//Removing the file named bill
	remove("bill.txt");
}

//Called function named add_item
void add_item(){
	system("color f2");
	
	int n,i,a,flag=0;
	int item_no,quantity;
    char name[50];
    float rate,amount;
	FILE *p;
	
	printf("\n---------------Enter the product details----------\n");
	p=fopen("store.txt","a");
	if(p==NULL)
	    printf("\nThe file doesnot exist\n");
	    
	printf("Enter the number of items to be added : ");
	scanf("%d",&n);
    	
	for (i=1 ; i<=n ; i++)
	{
		do{
			printf("Enter item number : ");
	     	scanf("%d",&item_no);
		    a=check_item_no(item_no);
		    if (a==0)
			    break;
			else
			    continue;    
		}while(a!=0);
		
		printf("Enter the item name : ");
		scanf("%s",name);
		printf("Enter the quantity : ");
		scanf("%d",&quantity);
		printf("Enter the rate of the item : ");
		scanf("%f",&rate);
		printf("\n");
		fprintf(p,"\n%d\t%s\t%d\t%.2f",item_no,name,quantity,rate);
	}
	printf("\n\n\n\t\t\t\t\t   ******* All items have been added successfully *******\n\n\n");
	fclose(p);
}

//Called function named display_item	
void display_item(){
	system("color f1");
	int item_no,quantity;
	char name[100];
	float rate;
	FILE *p;
	
	printf("\n\n                      **** Displaying all items ****                    \n\n");
    printf("\n------------------------------------------------------------");
	printf("\nItem_no\t\tName\t\tQuantity\tRate_Per_kg\n");
	printf("------------------------------------------------------------\n");
	
	p=fopen("store.txt","r");
	if(p==NULL)
	    printf("\nThe file doesnot exist\n");
	while(!feof(p))
	{
		fscanf(p,"%d\t%s\t%d\t%f\n", &item_no , name, &quantity , &rate);
		printf("%d\t\t%s\t\t%d\t\t%.2f\n", item_no , name ,quantity , rate);                   
	}
	fclose(p);
}

//Called function named search_item	
void search_item(){
	system("color f5");
	int item_no,quantity;
    char name[50];
    float rate,amount;
	int item_num;
	int flag=0;
	FILE *p;
		
	printf("Enter item number : ");
	scanf("%d",&item_num);
	
	p=fopen("store.txt","r");
	if(p==NULL)
	{
	    printf("\nThe file doesnot exist\n");
	}
	printf("\n                      **** Searching an item ****                    \n");
	printf("\n------------------------------------------------------------");
	printf("\nItem_no\t\tName\t\tQuantity\tRate_Per_kg\n");
	printf("------------------------------------------------------------\n");
	
	while(!feof(p))
	{
		fscanf(p,"%d\t%s\t%d\t%f\n", &item_no , name, &quantity , &rate);
		if  (item_num ==item_no)
		{			
			printf("%d\t\t%s\t\t%d\t\t%.2f\n", item_no , name ,quantity , rate);
			flag+=1;
		}
	}
	if(flag==0)
	{
		printf("-\t\t-\t\t-\t\t-\n");
		printf("\n\n\n\t\tSorry!!! This item number does not exists!\n\n\n");
	}
}

//Called function named check_item_no
int check_item_no(int item_num){
	int flag=0;
	FILE *p;
	int item_no,quantity;
    char name[50];
    float rate;
	
	p=fopen("store.txt","r");
	if(p==NULL)
	    printf("\nThe file doesnot exist\n");
	while(!feof(p))
	{
		fscanf(p,"%d\t%s\t%d\t%f\n", &item_no , name, &quantity , &rate);
		if  (item_num ==item_no)
		{
			printf("\nThis item number alrerady exists!\nPlease enter another item_number .\n\n");
			flag+=1;
			break;
		}                
	}
	
	fclose(p);
	return flag;	
}

//Called function named check_item_no_bill
int check_item_no_bill(int item_num){
	int flag=0;
	FILE *p;
	FILE *q;
	int item_no,quantity,item_quantity;
    char name[50],item_name[50];
    float rate , item_rate,amount;
	
	p=fopen("store.txt","r");
	if(p==NULL)
	    printf("\nThe file doesnot exist\n");
	q=fopen("bill.txt","a+");
	if(q==NULL)
	    printf("\nThe file doesnot exist\n");
	
	while(!feof(p))
	{
		fscanf(p,"%d\t%s\t%d\t%f\n", &item_no , name, &quantity , &rate);
		if  (item_num ==item_no)
		{
			strcpy(item_name,name);
			printf("Enter the quantity : ");
			scanf("%d",&item_quantity);
			item_rate=rate;
			amount=(item_rate * item_quantity);
			fprintf(q,"%d\t%s\t%d\t%.2f\t%.2f\n",item_num,item_name,item_quantity,item_rate,amount);
			flag+=1;
	   }
	}
	fclose(q);
	fclose(p);
	return flag;
}



