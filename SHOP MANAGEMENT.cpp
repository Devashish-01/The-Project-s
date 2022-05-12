//**************Project on Shop Management****************

//             Project created by- Devashish Patel
//                 Roll No. - 21MCF1R11
//                  MCA 1st Semester
//       Natinal Institute of Technology, Warangal
 
//****Header Files******
#include<conio.h>
#include<string.h>
#include<iostream>
#define MAX    100     //defining maximum no. of product
using namespace std;

//****defining class for Administrator********
class owner
{   	
      public:           // mamber variable
      
	int	 product_number[MAX];
	char product_name[50][MAX];
	float product_price[MAX],product_discount[MAX]; 
    static int count ;                                                       //static variable count for each product added

		void menu();
		void create();                         //member functions
		void remove();
		void modify();
		void list();
		void showfix();
		virtual void bill()
		{
			cout<<"it is a virtual function";          // virtual function
		}
		
};
int owner :: count = 0;               //definning static variable count to 0 
 
// new class customer publicaly inherited from class owner
//single inheritance
class customer : public owner
{
	int order_arr[50],quan[50];
	float total[100];            //declaring variable of class customer
	char ch4;
	char cus_name[100];
	string contact_no;
	 int c ;     
    public:
	customer()
	{                     //constructor customer used to initialize c = 0
		c=0;
	}	
	 
	void info();               //member functions of class customer
	void place_order();
	void bill();
		
};
       
void owner :: menu()        // function of class owner which contain various option for owner of the shop
{    
    

	system("cls");
	cout<<"\n";
   cout<<"\t\t\t\t----------------------------------------------------\n";
   cout<<"\t\t\t\t\t WELCOME TO ADMINISTRATOR MENU \n";
   cout<<"\t\t\t\t----------------------------------------------------\n";
   char ch2;
    cout<<"\n\n\t\t\t\t 1.ADD NEW PRODUCT";
    cout<<"\n\n\t\t\t\t 2.DISPLAY ALL PRODUCTS";                        //features for owner
    cout<<"\n\n\t\t\t\t 3.SEARCH SPECIFIC PRODUCTS ";
    cout<<"\n\n\t\t\t\t 4.MODIFY PRODUCT";
    cout<<"\n\n\t\t\t\t 5.DELETE PRODUCT";
    cout<<"\n\n\t\t\t\t 6.BACK TO MAIN MENU";
    cout<<"\n\n\n\n\t\t\t\tPlease Enter Your Choice (1-6) ";
    cin>>ch2;
	switch (ch2)            //use of switch case
    {
    case '1':
        system("cls");           //used to clear screen
        create();             //to add product create function will be called
        break;
    case '2':
        system("cls");
        list();           //to show all products list function will be called
        break;
    case '3':
        
        system("cls");
        showfix();         //to show a specific product showfix() will be called
        break;
		
    case '4':
    	
    	system("cls");
        modify();           //to modify the details of a product modify() will be called
        break;
        
    case '5':
    	
        remove();             //to delete a particular product remove() will be called
        break;
    
    case '6':             //it will again put the exicution of program to main menu
        break;
    default:
        cout << "\a";
        
    }
}
void owner :: create()   // when owner add some product this function is used
{
	  char ch;
	  cout<<"\n\t\t\t\t----------------------------------------------------\n";
	  cout<<"\t\t\t\t\t\t ADD NEW PRODUCT\n";
	  cout<<"\t\t\t\t----------------------------------------------------\n";
        do
		{
	    
		cout<<endl<<"\n\t\t\t\t Please Enter The Product code: ";
		cin>>product_number[count];                               //take product code in integer form
		cout<<endl<<"\n\t\t\t\t Please Enter The Name of The Product: ";
		cin.ignore();
		cin.getline(product_name[count] ,100);              //take product name  
		cout<<endl<<"\n\t\t\t\t Please Enter The MRP. of The Product: ";
		cin>>product_price[count];
		cout<<endl<<"\n\t\t\t\t Please Enter The Discount (%): ";          //discount
		cin>>product_discount[count];
	    count++;                           //count is increamented by 1 after a product is  added
	    cout<<"\n\t\t\t\t Product added successfully\n";
	    cout<<"\n\t\t\t\t do u want to add more product (y/n): ";
	    cin>>ch;
	  } while((ch=='y')||(ch=='Y'));               //ask owner to add more products
	  menu();
}
void owner :: list()    //this function shows the list of all products available
{
	cout<<"\n\t\t\t\t-------------------------------------------------------\n";
	  cout<<"\t\t\t\t\t\t  LIST OF ALL PRODUCTS AVAILABLE";
	  cout<<"\n\t\t\t\t-------------------------------------------------------\n\n\n";
	 
	  if(count==0) //check that product is added or not
	  {
	  	cout<<"\n\n \t\t\t\t\t No Product added.\n\t\t\t\t\t first add product";
	  }
	  else    //if product has added then show the list
	  {
	  cout<<"\n\t\t\t--------------------------------------------------------------------------------\n";
	  cout<<"\t\t\t\t CODE \t\t NAME \t\t MRP \t\t DISCOUNT(%)";
	   cout<<"\n\t\t\t--------------------------------------------------------------------------------\n";
	  for(int i=0;i<count;i++)
	  {
	  	cout<<"\n\t\t\t\t "<<product_number[i]<<" \t\t "<<product_name[i]<<"\t\t "<<product_price[i]<<"\t\t "<<product_discount[i]<<"\n\n";
	  }
	  cout<<"\n\t\t\t--------------------------------------------------------------------------------------\n";
      }
}
void owner :: showfix()  //it will show the information about a specific product
{
	int code;
	char ch1;
   if(count==0)          //check that product is added or not
	  {
	  	cout<<"\n\n \t\t\t\t\t No Product added.\n\t\t\t\t\t first add product";
	  }
	  else            //if product has added then show the information of that particular product
	  do	
	  { 
	    int found=0;       
	   cout << "\n\n\t\t\t\tPlease Enter The Product CODE : ";
        cin >> code;
	     for(int i=0;i<count;i++)
	    {                              //search for that product in the list
	      if(code==product_number[i])
	      {
	   	     cout<<"\n\t\t\t\t-------------------------------------------------------------------------\n";
	         cout<<"\t\t\t\t\t CODE \t\t NAME \t\t MRP \t\t DISCOUNT(%)";
	         cout<<"\n\t\t\t\t--------------------------------------------------------------------------\n";
	         cout<<"\n\t\t\t\t\t "<<product_number[i]<<" \t\t "<<product_name[i]<<"\t\t "<<product_price[i]<<"\t\t "<<product_discount[i]<<"\n\n";
	         cout<<"\n\t\t\t\t---------------------------------------------------------------------------\n";
	         found++;
           }
	   }
       
      if(found==0)          //check if product not found
      {
      	cout<<"\n\n \t\t\t\t\t No such product found \n ";
	  }
   
	   cout<<"\n\t\t\t\t do u want to perform for more product (y/n): ";
	    cin>>ch1;
	  } while((ch1=='y')||(ch1=='Y'));   //ask owner if he want to search more products
	
}
void owner :: modify()   //if owner wants to make changes this function will change info. of specific product
{
	int cd;
	
	char ch2;
   if(count==0)           //check that product is added or not in the list
	  {
	  	cout<<"\n\n \t\t\t\t\t No Product added.\n\t\t\t\t\t first add product";
	  }
	  else            //if list is not empty then modify the information of that particular product
	  do	
	  {  
	    int f=0;
	  cout << "\n\n\t\t\t\tPlease Enter The Product CODE : ";  //ask the code for that particular product
        cin >> cd;
	     for(int i=0;i<count;i++)               //ask the code for that particular product
	    {
	      if(cd==product_number[i])           //if found then allow owner to modify it and enter new detail
	      {
	   	        cout<<endl<<"\n\t\t\t\t Please Enter New The Product code: ";
	         	cin>>product_number[i];
		        cout<<endl<<"\n\t\t\t\t Please Enter The New Name of The Product: ";
		         cin.ignore();
		        cin.getline(product_name[i] ,100);
		        cout<<endl<<"\n\t\t\t\t Please Enter The New MRP. of The Product: ";
		         cin>>product_price[i];
		         cout<<endl<<"\n\t\t\t\t Please Enter The Discount (%): ";
		         cin>>product_discount[i];

	              f++;     //if froduct found f is increamented by 1
	              
           }
	   }
	   
       
      if(f==0)           //if such product not found 
      {
      	cout<<"\n\n \t\t\t\t\t No such product found \n ";
	  }
   
	   cout<<"\n\t\t\t\t do u want to modify more product (y/n): ";  
	    cin>>ch2;
	  } while((ch2=='y')||(ch2=='Y'));    //ask user for more modification
	
}
void owner :: remove()  // delete the particular products from the list
{
     int pcd;
	
	char ch3;
   if(count==0)       // check that list is empty or not
	  {
	  	cout<<"\n\n \t\t\t\t\t No Product added.\n\t\t\t\t\t first add product";
	  }
	  else            //if list is not empty then procced to delete
	  do	
	  {  int f=0;
	    
	    cout << "\n\n\t\t\t\tPlease Enter The Product CODE TO DELETE : ";      //ask the code for that particular product
        cin >> pcd;
	     for(int i=0;i<count;i++)                              //ask the code for that particular product
	    {
	      if(pcd==product_number[i])                         //if found than allow user to delete it 
	      {	
	         f++;                                             //if froduct found f is increamented by 1
	        if(i==count-1)
	        {                                        //if user choose last product to delete decreament count by 1
	      	count--;
		    }
		    else                                   //otherwise shift all the products up other than that particular products
		    {
		    	for(int j=i;j<count-1;j++)
		    	{
		    		product_number[j]=product_number[j+1];
		    		strcpy(product_name[j],product_name[j+1]);
		    		product_price[j]=product_price[j+1];
		    		product_discount[j]=product_discount[j+1];
		    		
				}
		    	count--;  //then decreament count by 1
			}
		}
	}
	if(f==0)     //if no such product is available
      {
      	cout<<"\n\n \t\t\t\t\t No such product found \n ";
	  }
       cout<<"\n\n \t\t\t\t\t product deleted \n";
	   cout<<"\n\t\t\t\t do u want to modify more product (y/n): ";
	    cin>>ch3;
	  } while((ch3=='y')||(ch3=='Y'));           //ask user to delete more
	
}
//**********customer Part***************
void customer :: info()      //will take information of customer
{
	system("cls");
   cout<<"\n";
 	cout<<"\t\t\t\t----------------------------------------------------\n";
   cout<<"\t\t\t\t\t WELCOME TO PATANJALI MEGA STORE \n";
   cout<<"\t\t\t\t----------------------------------------------------\n";
   cout<<"\n\n";
   cout<<"\t\t\t\t\t Customer Name : ";
   cin.ignore();
   cin.getline(cus_name,100);
   cout<<"\n\n";
   cout<<"\t\t\t\t\t Customer Contact number : ";
   cin>>contact_no;
   cout<<"\n\n\n\t\t\t\t\t\tTHANK YOU ";
   
   getch();
}
void customer :: place_order()   // take order of customer's choice which he want to buy
{     
    char ch5;
    int counter;
	cout<<"\n\n\n\t\t\t\t\tdo u want to place order (y/n)";    //ask user to buy
	cin>>ch5;
	if((ch5=='Y')||(ch5=='y'))        //if yes then take order
	{   
	   counter=0;
        cout<<"\n\t\t\t******************************************************\n";
	    cout<<"\t\t\t\t\t PLACE YOUR ORDER";
     	cout<<"\n\t\t\t******************************************************\n";
	   do
	   {
		cout<<"\n\n\t\t\t\t\t Enter The Product code : "; //customer will only enter the product code which he want to buy
		cin>>order_arr[c];
		cout<<"\n\t\t\t\t\t Quantity: ";   // ask for the quantity
		cin>>quan[c];
		
			for(int i=0;i<count;i++)           //search that product
			{
				if(order_arr[c]==product_number[i])
				{
				total[c]=quan[c]*(product_price[i]-(product_price[i]*product_discount[i])/100);
				c++;
				counter++;
				}
		    }
		if(counter==0)  //if no such product is there
		{
			cout<<"\n\t\t\t\t\t Invalid Product Code\n";
		}
		cout<<"\n\t\t\t\t\tDo You Want To Order Another Product ? (y/n)"; //ask to order more products
		cin>>ch4;
	  }  while(ch4=='y' || ch4=='Y');
	                                   //customer has done he dont want to buy more now
	cout<<"\n\n\t\t\t\t\tThank You For Purchassing\n";
	getch();
	
	}
		
}
void customer :: bill()    // it will generate the bill of the coustomer
{     system("cls");
      int grandt=0;
      cout<<"\n\t\t\t\t\t\t***************************************************************\n";
      cout<<"\t\t\t\t\t\t\t\t\tINVOICE";
      cout<<"\n\t\t\t\t\t\t***************************************************************\n";
      cout<<"\n\n\t\t\t-------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t\t\tPATANJALI MEGA STORE , INDORE ";
	cout<<"\n\n\t\t\t\t\tSakshi Rathore   contact no. - 7834542339 \n";     //shop name and further details displayed on bill
	cout<<"\t\t\t\t\tBhawarkua Square , Indore 452014";
	cout<<"\t\twww.patanjalindore.com";
	cout<<"\n\n\t\t\t---------------------------------------------------------------------------------------------------------------\n";
      cout<<"\n\t\t\t-----------------------------------------------------------------------------------------------------------------\n";
	  cout<<"\t\t\t\t Customer Detail     Name : "<<cus_name<<"\t\t Contact No. : "<<contact_no; //display customer's  name and contact no.
	   cout<<"\n\t\t\t----------------------------------------------------------------------------------------------------------------\n";
      cout<<"\n\t\t\t----------------------------------------------------------------------------------------------------------------\n";
	  cout<<"\t\t\t\t CODE \t\t Product \t Quantity \t MRP \t\t DISCOUNT(%) \t\t total ";  
	   cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------------\n";
	   
	  for(int i=0;i<count;i++)
	  {                              //it will list all the products purchesed by user with price after the discount
	    for(int j=0;j<c;j++)
	    {
	     if(order_arr[j]==product_number[i])
	     {
	  	   cout<<"\n\t\t\t\t "<<product_number[i]<<" \t\t "<<product_name[i]<<"\t\t "<<quan[j]<<"\t\t"<<product_price[i]<<"\t\t "<<product_discount[i]<<"\t\t\t"<<total[j]<<"\n\n";
	  	   grandt=grandt+total[j];
	     }
	   }
      }      //atlast show the total amount for whole shopping
	  cout<<"\n\t\t\t-----------------------------------------------------------------------------------------------------------------\n";
	  cout<<"\t\t\t\t\t\t GRAND TOTAL AMOUNT  \t\t\t\t\t\tRs."<<grandt;
       cout<<"\n\t\t\t-----------------------------------------------------------------------------------------------------------------\n";
       
       c=0;
       grandt=0;     //again putting the variable to 0 for new customer
       getchar();
}
//************* main function ***************
int main()
{   
 
 customer cu;
   int ch;
   while(true)
   {
   	system("cls");
   cout<<"\n";
   cout<<"\t\t\t\t----------------------------------------------------\n";
   cout<<"\t\t\t\t\t WELCOME TO PATANJALI MEGA STORE \n";
   cout<<"\t\t\t\t----------------------------------------------------\n";
   cout<<"\n\n";
   cout<<"\t\t\t\t\t  1. ADMINISTRATOR  \n";           //ask user's choice if he is a owner or customer
   cout<<"\t\t\t\t\t  2. CUSTOMER \n";
   cout<<"\t\t\t\t\t  3. EXIT \n\n\n";
   cout<<"\t\t\t\t\t  Please select an option (1-3) : ";
   cin>>ch;
   
   switch(ch)
		{
			
			case 1: 
			       {
					system("cls");  //if user is owner then call the menu() having different options for owner
					cu.menu();
			        getch();
					break;
					}
				
			case 2:               //if user is a customer 
					  {
					   	system("cls");
					  
					  if(cu.count==0)   //check if there is no product in list
					  {
					   cout<<"\n\n\t\t\t\t\tNo products added yet \n";
				     }
				     else     //if list is not empty
				     {
					  cu.info();  //call info() to take customer detail
					  system("cls");
					  cu.list();     //then show the list of available products
					  cu.place_order();   //then take the order 
					  cu.bill();       //at last it will show the bill of the products purchased
				     }
				     getch();
					   break;
			         }
					
			case 3: //if user press 3 to exit then it will exit from the output screen
					cout<<"\n\n\t\t\t\t----------------------------------------------------";
					cout<<"\n\t\t\t\t\t\tTHANK YOU ! Good Bye! \n";
				    cout<<"\t\t\t\t----------------------------------------------------\n";
					exit(0);
			
			default :        //if user enters something else other than (1-3)
			 {  cout<<"\n\n\t\t\t\t----------------------------------------------------";
			    cout<<"\n\t\t\t\t\t\tInvalid Input !!!";
			    cout<<"\n\t\t\t\t----------------------------------------------------";
				cout<<"\n\n\t\t\t\t\t  Please select an option (1-3) : ";
				cin>>ch;
		    }
        }
    }
	return 0;         //that is all about the billing system and shop management project
}
//******************end of program**********