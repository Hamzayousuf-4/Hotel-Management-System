#include "HMS.h"

void removeallfiles() {
	remove(ownerfile);
	remove(customerfile);
	remove(managerfile);
	remove(receptionistfile);
	remove(managerfile);
	remove(receptionistfile);
	remove(billsfile);
	remove(Roomfile);
	remove(complainfile);
	int x = 0;
	f.open(uniqueIDfile, ios::out | ios::binary);
	f.write((char*)&x, sizeof(int));
	f.close();
	f.open(Invoicefile, ios::out | ios::binary);
	f.write((char*)&x, sizeof(int));
	f.close();
}
void creatingemptyfiles(){
	f.open(ownerfile, ios::out | ios::binary);
	f.close();
	
	f.open(managerfile, ios::out | ios::binary);
	f.close();
	
	f.open(receptionistfile, ios::out | ios::binary);
	f.close();
	
	f.open(billsfile, ios::out | ios::binary);
	f.close();
	
	f.open(Roomfile, ios::out | ios::binary);
	f.close();
	
	f.open(complainfile, ios::out | ios::binary);
	f.close();
	
}
void initilizerooms(){
	f.open(Roomfile,ios::app|ios::binary);
	for(int i=0;i<30;i++){
		Room r;
		 r.RoomNo=i+1;
		 r.Status=false;
		if(i<20){
			strcpy(r.Type,"AC");
		}
		else{
			strcpy(r.Type,"NON-AC");
		}
		
		f.write((char*)&r,sizeof(r));
	}
	f.close();
}




void setup() {
	removeallfiles();
	creatingemptyfiles();
	owner a;
	cout<<"ENTER OWNER DETAILS\n";
	a.setname();
	a.setAddress();
	a.setPhoneNo();
	a.setpassword();
	clear();
	f.open(ownerfile, ios::out);
	f.write((char*)&a, sizeof(a));
	f.close();
	a.details();
	initilizerooms();
}


int main() {
	system("COLOR 71");
	cout<<"SETTING UP EVERYTHING!\n";
	clear();
	setup();
	
}




