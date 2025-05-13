#include "HMS.h"
using namespace std;
welcome(){
	cout<<" -------------------------------------------------------------------------\n" ;
	cout<<"|                                                                         |\n" ;      
	cout<<"|                                                                         |\n" ;
	cout<<"|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n" ;
	cout<<"|  O        O    O O      O        O      O    O O    O O        O        |\n" ;
	cout<<"|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n" ;
	cout<<"|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n" ;
	cout<<"|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n" ;
	cout<<"|                                                                         |\n" ;                       
	cout<<" -------------------------------------------------------------------------\n" ;
	cout<<"\t\t*************************************************\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*       -----------------------------           *\n" ;
	cout<<"\t\t*           WELCOME TO  HOTEL MANAGMENT SYSTEM  *\n" ;
	cout<<"\t\t*       -----------------------------           *\n" ;
	cout<<"\t\t*                 OWNERS APPLICATION            *\n" ;
	cout<<"\t\t*             Project By:                       *\n" ;
	cout<<"\t\t*         HAMZA YOUSUF                      		*\n" ;
	cout<<"\t\t*             			                    	 *\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*                        					    *\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*                           					  *\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*                                               *\n" ;
	cout<<"\t\t*************************************************\n\n\n" ;
}


int Menu3(){

	int choice;
	clear();
	cout<<endl<<endl;
	cout<<"		PRESS 1 FOR VIEWING BILLS\n";
	cout<<"		PRESS 2 TO ADD CUSTOMER\n";
	cout<<"		PRESS 3 FOR CUSTOMER CHECKOUT\n";
	cout<<"		PRESS 4 TO CHECK ROOMS DETAILS\n";
	cout<<"		PRESS 5 FOR VIEWING GUEST INFO\n";
	cout<<"		PRESS 6 TO EXIT\n";
	cout<<"ENTER YOUR CHOICE: ";
	cin>>choice;
	return choice;
}

int main3(){
	system("COLOR 10");
	start();
	welcome();
	Receptionist a;
	bool check;
	a.details();
	check=status(a,3);			
	int choice;
	
	while(check){
		choice=Menu3();
		switch(choice){
			case 1:{
				a.ViewBills();
				break;
			}				
			case 2:{
				a.addcustomerdetail();
				break;
			}			
				
			case 3:{
				a.Customercheckout();
				break;
			}	
			case 4:{
				a.ViewRoominfo();	
				break;
			}
			case 5:{
				a.ViewAllGuestinfo();
				break;
			}
		
				
		}
		if(choice==6){
			break; 	
		}
		
	}
	
}

int Menu2(){
	int choice;
	cout<<"PRESS 1 TO MANAGE A MANAGER\n";
	cout<<"PRESS 2 TO VIEW ROOMS INFO\n";
	cout<<"PRESS 3 TO VIEW GUEST INFO\n";
	cout<<"PRESS 4 TO VIEW THE Bills\n";
	cout<<"PRESS 5 TO MANAGE COMPLAINS\n";
	cout<<"PRESS 6 TO EXIT\n";
	cin>>choice;
	return choice;
}

int main2(){
	system("COLOR 65");
	start();
	welcome();
	owner a;	 	 	
	status(a,1);
				
				
	int choice;
	bool check;
	
	do{
		clear();
		choice=Menu2();
		switch(choice){
			case 1:{
				clear();
				cout<<"PRESS 1 TO APPOINT MANAGER\n";
				cout<<"PRESS 2 TO REMOVE MANAGER\n";
				cout<<"ENTER YOUR CHOICE: ";
				cin>>choice;
				if(choice==1){
					a.appointmanager();
				}
				else if(choice==2){
					a.removemanager();
				}
				break;
			}
				
			case 2:{
				clear();
				a.ViewRoominfo();
				break;
			}
				
			case 3:
				clear();
				a.ViewAllGuestinfo();
				break;
			case 4:
				clear();
				a.ViewBills();
				break;
			case 5:
				clear();
				a.ViewComplains();
			break;
			case 6:
				system("CLS");
				cout<<"BYE BYE\n";
				break;	
		}
		if(choice==6){
			break;
		}
		
	}while(choice!=6);
	
}

int Menu1(){
	int choice;
	cout<<"PRESS 1 TO MANAGE A RECEPTIONIST\n";
	cout<<"PRESS 2 TO VIEW ROOMS INFO\n";
	cout<<"PRESS 3 TO VIEW GUEST INFO\n";
	cout<<"PRESS 4 TO VIEW BILLS\n";
	cout<<"PRESS 5 TO ADD COMPLAIN\n";
	cout<<"PRESS 6 TO EXIT\n";
	cin>>choice;
	return choice;
}


int main1(){
	system("COLOR 71");
	start();
	welcome();
	Manager a;
	bool check;
	check=status(a,2);			
	int choice;
	
	while(check){
		clear();
		choice=Menu1();
		switch(choice){
			case 1:{
				clear();
				cout<<"PRESS 1 TO ADD RECEPTIONIST\n";
				cout<<"PRESS 2 TO REMOVE RECEPTIONIST\n";
				cin>>choice;
				if(choice==1){
					a.appointReceptionist();
				}
				else if(choice == 2){
					a.removeReceptionist();
				}
				
			
				break;
			}				
		
			case 2:{
				a.ViewRoominfo();
			
				break;
			}			
				
			case 3:{
				a.ViewAllGuestinfo();
			
				break;
			}	
			case 4:{
				a.ViewBills();
				break;
			}
			case 5:{
				a.RecordComplaints();
			
				break;
			}
			case 6:{
				
				break;
			}
				
		
				
		}
		if(choice==6){
			break;
		}
		
	}
}

// Owner Application
void ownerApplication() {

main2();
}



// Manager Application
void managerApplication() {

main1();
}    



// Receptionist Application
void receptionistApplication() {
 
 main3();  
}

int Menu() {
    int choice;
    cout << "PRESS 1 FOR OWNER APPLICATION\n";
    cout << "PRESS 2 FOR MANAGER APPLICATION\n";
    cout << "PRESS 3 FOR RECEPTIONIST APPLICATION\n";
    cout << "PRESS 4 TO EXIT\n";
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;
    return choice;
}

int main() {
    int choice;
    bool check;

    do {
        choice = Menu();

        switch (choice) {
            case 1:
                ownerApplication();
                break;

            case 2:
                managerApplication();
                break;

            case 3:
                receptionistApplication();
                break;

            case 4:
                cout << "Exiting...\n";
                check = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (check);

    return 0;
}
