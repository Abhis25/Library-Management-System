using namespace std;
#include<iostream>
#include<stdlib.h>
#include"Transaction.cpp"
int main(){
	int choice;
	char ans;
	Book b;
	students s;
	Transaction t;
	do{
	
	cout<<"1. Book Menu"<<endl;
	cout<<"2. Student Menu"<<endl;
	cout<<"3. Transaction Menu"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Enter your choice "<<endl;
	cin>>choice;
	switch(choice){
	case 1:
		b.menu();
		break;
	case 2:
		s.menu();
		break;
	case 3:
		t.menu();
		break;
	case 4:
		exit(0);
	}
	cout<<"\nDo you want to perform more operation\n"<<endl;
	fflush(stdin);
	cin>>ans;
	}while(ans=='y'||ans=='Y');
}
