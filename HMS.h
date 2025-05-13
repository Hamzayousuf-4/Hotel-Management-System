#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;

#ifndef HMS_H
#define HMS_H

//files used and made it into variable to make sure names of files remain same
char ownerfile[] = "Owner.dat";
char customerfile[] = "Customer.dat";
char managerfile[] = "Manager.dat";
char receptionistfile[] = "receptionistfile.dat";
char billsfile[] = "Bills.dat";
char Roomfile[] = "Rooms.dat";
char FoodItemsfile[] = "FoodItem.dat";
char complainfile[] = "Complains.dat";
char uniqueIDfile[] = "UNIQUE_ID.dat";
char Invoicefile[] = "Invoice.dat";
char Tempfile[] = "Temp.dat";



//will be used for managing files
fstream f;
fstream temp;
fstream f2;



//function for clearing screen
void clear() {
	cout << "Press any key to continue!";
	getch();
	system("CLS");
}
static int UniqueID;
static int Invoice;

void start(){
		//reading value of unique ID from file
		f.open(uniqueIDfile, ios::in | ios::binary);
		f.read((char*)&UniqueID, sizeof(int));
		f.close();
		//reading value of Invoice from file
		f.open(Invoicefile, ios::in | ios::binary);
		f.read((char*)&Invoice, sizeof(int));
		f.close();
}
//function for updating value of Unique ID
void updateUniqueID() {
	f.open(uniqueIDfile, ios::out | ios::binary);
	f.write((char*)&UniqueID, sizeof(int));
	f.close();
	}

	//function for updating value of Invoice
void updateInvoice() {
	f.open(uniqueIDfile, ios::out | ios::binary);
	f.write((char*)&Invoice, sizeof(int));
	f.close();
	}

//class of Hotel managment system
class HMS {
protected:
};


//class compain for managing complains
class Complain :public HMS{
	char Name[25];
	char what[1000];
	friend class owner;
	friend class Manager;
};

//class Customers for managing Customers Record
class Customer :public HMS {
	int ID;
	char name[25];
	char PhoneNo[14];
	char Address[100];
	int roomno;
	friend class Room;
	friend class Bill;
	friend class Receptionist;
	
	public:
		Customer(){
			ID = UniqueID++;
			updateUniqueID();
		}
	void details(){
		cout<<"ENTER NAME: ";
		fflush(stdin);
		cin.get(name,25);
		cout<<"ENTER PHONE NO: ";
		fflush(stdin);
		cin.get(PhoneNo,14);
		cout<<"ENTER ADDRESS: ";
		fflush(stdin);
		cin.get(Address,100);
	}
	//display function used for Displaying Customer Data
	void display() {
		cout << "ID: " << ID << endl;
		cout << "NAME: " << name << endl;
		cout << "PHONE NUMBER: " << PhoneNo << endl;
		cout << "ADDRESS: " << Address << endl;
		cout << "ROOM NUMBER: " << roomno << endl;
	}
};
//class Room is used for holding the record of room,It's status(ocupied or not)
class Room :public HMS {
	int RoomNo;
	char Type[15];
	bool Status;
	friend void initilizerooms();
	friend class Receptionist;
public:
	//Function For Guest's Info Inside the Room
	void GuestInfo() {
		if (Status == false) {
			cout << "THIS ROOM HAVE NO GUEST!\n";
		}
		else {
			Customer c;
			f.open(customerfile, ios::in | ios::binary);
			while (!f.eof()) {
				if (f.read((char*)&c, sizeof(c))) {
					if (c.roomno == RoomNo) {
						c.display();
						break;
					}
				}
			}
		}
	}

	//function for updating Room status to Empty
	void updateRoomStatustoempty() {
		Room c;
		c.Status=false;
}


	//function for updating Room status to Full
	void updateRoomStatustofull() {
		Room c;
		c.Status=true;
	}
	
	//Function to Display Rooms Data
	void display(){
		cout<<"ROOM NO: "<<RoomNo<<endl;
		cout<<"TYPE: "<<Type<<endl;
		if (Status){
			cout<<"Status: OCUPIED"<<endl;
		}
		else{
			cout<<"Status: VACANT"<<endl;
		}	
	}

};


class Bill :public HMS {
	int BillNo;
	float Billamount;
	char CustomerName[25];

	
public:
	Bill(){
		BillNo=Invoice++;
		updateInvoice();
	}
	//function for Generating and printing of bill
	void GenerateBill(Customer c) {
		clear();
		strcpy(CustomerName, c.name);
						
		BillNo = Invoice++;
		updateInvoice();
		cout << "ENTER BILL AMOUNT: ";
		cin >> Billamount;
		cout << "----------------BILL GENERATED------------------------\n";
		cout << "INVOICE NUMBER: " << BillNo << endl;
		cout << "CUSTOMER ID: " << c.ID << endl;
		cout << "CUSTOMER NAME: " << CustomerName << endl;
		cout << "BILL AMOUNT: " << Billamount << endl;
		clear();
		display();
		addbilltorecord(*this);
		
		
	}
	void addbilltorecord(Bill b){
		f.open(billsfile,ios::app|ios::binary);
		f.write((char*)&b,sizeof(b));
		f.close();
	}
	
	
	void display(){
		cout << "INVOICE NUMBER: " << BillNo << endl;
		cout << "CUSTOMER NAME: " << CustomerName << endl;
		cout << "BILL AMOUNT: " << Billamount << endl;
	}
};




//class Employee to handle Employees Record and Functionality
class Employee :public HMS {
protected:
	int EmployeeID;
	char name[25];
	char password[25];
	char PhoneNo[13];
	char Address[100];

	void setpassword() {

		bool match;
		int i = 0;
		char pass[25];
		char PASS[25];
		do {
			i++;
			cout << "ENTER THE NEW PASSWORD: ";
			fflush(stdin);
			cin.get(pass, 25);

			cout << "ENTER THE NEW PASSWORD AGAIN: ";
			fflush(stdin);
			cin.get(PASS, 25);
			if (strcmp(pass, PASS) == 0) {
				match = true;
			}
			else
			{
				match = false;
				cout << "PASSSWORDS DOESN'T MATCH\n";
			}
			if (i == 3 && match == false) {
				cout << "TO MANY ATTEMPTS!\n";
				break;
			}
			clear();

		} while (!match);

		if (match) {
			strcpy(password, pass);
			cout << "PASSWORD HAS BEEN SET\n";
		}
	}
public:
	Employee() {
	 	EmployeeID = UniqueID++;
		updateUniqueID();
	}

	void setname() {
		cout << "ENTER FULL NAME: ";
		fflush(stdin);
		cin.get(name, 25);
	}
	void setPhoneNo() {
		cout << "ENTER PHONE NUMBER: ";
		fflush(stdin);
		cin.get(PhoneNo, 13);
	}
	void setAddress() {
		cout << "ENTER ADDRESS: ";
		fflush(stdin);
		cin.get(Address, 100);
	}

	string getname() {
		return name;
	}
	string getPhoneNo() {
		return PhoneNo;
	}
	string getAddress() {
		return Address;
	}
	
	template<typename t1>
	bool login(t1 &a,int T) {
		bool s=false;
		int ID;
		char Password[25];
		clear();
		cout << "ENTER USER-ID AND PASSWORD :\n";
		cin >> ID;
		fflush(stdin);
		cin.get(Password, 25);
		if(T==1){
			f.open(ownerfile,ios::in | ios::binary);
		}
		else if(T==2){
			f.open("Manager.dat",ios::in | ios::binary);
		}
		else if(T==3){
			f.open("receptionistfile.dat",ios::in | ios::binary);
		}     	
		while(!f.eof()){
			if(f.read((char*)&a,sizeof(a))){
				if (a.EmployeeID == ID && strcmp(a.password, Password) == 0){
					s=true;
					break;
				}
					
		 	}	
			else{ 	
				s=false;
			} 
 		}
 		f.close();
 		return s;
		
	}
	void ViewAllGuestinfo() {
		Customer c;
		f.open(customerfile, ios::in | ios::binary);
		while (!f.eof()) {
			if (f.read((char*)&c, sizeof(c))) {
				cout << endl << endl;
				c.display();
			}
		}
		f.close();
		clear();
	}
	void ViewRoominfo() {
		Room c;
		f.open(Roomfile, ios::in | ios::binary);
		while (!f.eof()) {
			if (f.read((char*)&c, sizeof(c))) {
				cout << endl << endl;
				c.display();
			}
		}
		f.close();
		clear();
	}
	void ViewBills() {
		Bill c;
		f.open(billsfile, ios::in | ios::binary);
		while (!f.eof()) {
			if (f.read((char*)&c, sizeof(c))) {
				cout << endl << endl;
				c.display();
			}
		}
		f.close();
	}

	void details() {
		cout << "NAME = " << name << endl;
		cout << "PHONE NUMBER = " << PhoneNo << endl;
		cout << "ADDRESS = " << Address << endl;
		cout << "--------------LOGIN DETAILS-----------------\n";
		cout << "         EMPLOYEE ID = " << EmployeeID << endl;
		cout << "         PASSWORD = " << password << endl;
	}
};

class Receptionist :public Employee {
	friend class Manager;
public:
	void CheckRoomAvailibilty() {
		Room c;
		f.open(Roomfile, ios::in | ios::binary);
		while (!f.eof()) {
			if (f.read((char*)&c, sizeof(c))) {
				cout << endl << endl;
				c.display();
			}
		}
		f.close();
		clear();

	}

	void addcustomerdetail(){
		Room r[30];
		Customer c;
		c.details();
		f.open(Roomfile,ios::in|ios::binary);
		for(int i=0;i<30;i++){
			f.read((char*)&r[i],sizeof(r[i]));
		}
		f.close();
		int Type;
	
		cout<<"PRESS 1 FOR AN AC ROOM\n";
		cout<<"PRESS 2 FOR A NON AC ROOM\n ";
		cin>>Type;
		switch(Type){
			case 1:
				{
					for(int i=0;i<20;i++){
						if(r[i].Status==false){
							c.roomno=r[i].RoomNo;
							r[i].updateRoomStatustofull();
						}
					
					}
					break;
					
				}
			case 2:
				{
				for(int i=20;i<30;i++){
						if(r[i].Status==false){
							c.roomno=r[i].RoomNo;
							r[i].updateRoomStatustofull();
						}
					}
					break;
				}
				
		}
		f.open(Roomfile,ios::out|ios::binary);
		for(int i=0;i<30;i++){
			f.write((char*)&r[i],sizeof(r[i]));
		}
		f.close();
		f.open(customerfile,ios::app|ios::binary);
		f.write((char*)&c,sizeof(c));
		f.close();
		GenerateBill(c);
	}
	void GenerateBill(Customer c) {
		Bill b;
		b.GenerateBill(c);
	}
	void Customercheckout(){
		int id;
		Customer c;
		clear();
		cout<<"ENTER CUSTOMER ID: ";
		cin>>id;
		int rn;
		f.open(customerfile,ios::in|ios::binary);
		temp.open(Tempfile,ios::out|ios::binary);
		while(!f.eof()){
			f.read((char*)&c,sizeof(c));
			if(c.ID==id){
				rn=c.roomno;
			}
			else
			{
				temp.write((char*)&c,sizeof(c));
			}
			
		}
		f.close();
		temp.close();
		remove(customerfile);
		rename(Tempfile,customerfile);
		
		
		Room r[30];
		f.open(Roomfile,ios::in|ios::binary);
		for(int i=0;i<30;i++){
			f.read((char*)&r[i],sizeof(r));
		}
		r[rn-1].updateRoomStatustoempty();
		f.open(Roomfile,ios::out|ios::binary);
		for(int i=0;i<30;i++){
			f.write((char*)&r[i],sizeof(r[i]));
		}
		f.close();
			
	}
};

class Manager :public Employee {
	friend class owner;
public:

	void RecordComplaints(){
		Complain c;
		cout << "ENTER NAME OF THE PERSON WHO IS COMPAINING: ";
		fflush(stdin);
		cin.get(c.Name, 25);
		cout << "ENTER THE COMPLAIN: " << endl;
		fflush(stdin);
		cin.get(c.what, 1000);
		f.open(complainfile, ios::app);
		f.write((char*)&c, sizeof(c));
		f.close();
	}
	void appointReceptionist(){
		Receptionist a;
		a.setname();
		a.setAddress();
		a.setPhoneNo();
		a.setpassword();
		a.details();
		clear();
		f.open(receptionistfile,ios::out|ios::binary);
		f.write((char*)&a,sizeof(a));
		f.close();
	}
	void removeReceptionist(){
		remove(receptionistfile);
		cout<<"RECEPTIONIST REMOVED!\n";
		clear();
	}
	void ManageStaff() {

	}

};

class owner :public Employee {
	friend void setup();
	friend void readdata(owner &a);
public:
	void appointmanager(){
		Manager a;
		a.setname();
		a.setAddress();
		a.setPhoneNo();
		a.setpassword();
		a.details();
		clear();
		f.open(managerfile,ios::out|ios::binary);
		f.write((char*)&a,sizeof(a));
		f.close();
	}
	void removemanager(){
		remove(managerfile);
		f.open(managerfile,ios::out|ios::binary);
		f.close();
		cout<<"MANAGER REMOVED!\n";
		clear();
	}
	void ViewComplains(){
		Complain c;
		f.open(complainfile, ios::in | ios::binary);
		while (!f.eof()) {
			if (f.read((char*)&c, sizeof(c))) {
				cout << endl << endl;
				cout << c.what << endl;
				cout << "                              Complain by : " << c.Name << endl;
			}
		}
		f.close();
	}
};

template<class x>
bool status(x &a,int b){
	bool check=false;
	int cont=0;
	check;
	do{
		check=a.login(a,b);
		cont=0;
		if(check){
			cout<<"LOGIN SUCESSFULL!\n";
		}
		else {
			cout<<"LOGIN FAILED!\n";
			cout<<"DO YOU WANT TO CONTINUE?PRESS 1 TO CONTINUE ELSE PRESS 0\n";
			cin>>cont;
		}
	}while(cont==1);
	return check;
}

#endif
