using namespace std;
#include<iostream>
#include "Book.cpp"
#include "Student.cpp"
#define TName "transaction.txt"
class Transaction{
	int tid,sid,bid;
	char idate[12],rdate[15];
	public:
	void issueBook();
	void showIssuedBookbySid(int sid);
	void returnBook();
	int getLatestID();
	void menu();
};
void Transaction::menu(){
	int choice;
	char ans;
	int sid;
	do{
	
	cout<<"\n1 for Issue";
	cout<<"\n2 for Return";
	cout<<"\n3 for checkBookStatus";
	cout<<"\n4 for check Student detail";
	cout<<"\n5 for exit";
	cout<<"\nenter choice\n";
	cin>>choice;
	switch(choice){
		case 1:
			this->issueBook();
			break;
		case 2:
			this->returnBook();
			break;
		case 3:
			Book obj;
			obj.readBookbyBid();
			break;
		case 4:
			cout<<"enter sid";
			cin>>sid;
			this->showIssuedBookbySid(sid);
			break;
			
	}
	cout<<"\ndo you want to continue Transactions\n";
	fflush(stdin);
	cin>>ans;
	
	
	}while(ans=='y'||ans=='Y');

}
int Transaction::getLatestID(){
			fstream f;
			Transaction b;
			f.open(TName,ios::in);
			int max=0;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.tid>max)
				max=b.tid;
			}
		return (max+1);
		}
void Transaction::issueBook()
{
	Book b;
	students s;
	cout<<"enter Bookid -> ";
	cin>>bid;
	if(b.bookExist(bid))
	{
		if(strcmp(b.getStatus(bid),"available")==0)
		{
			cout<<"enter sid -> ";
			cin>>sid;
			if(s.studentExist(sid))
			{
				cout<<"enter date -> ";
				cin>>idate;
				strcpy(rdate,"pending\n");
				tid=this->getLatestID();
				fstream fp;
				fp.open(TName,ios::app);
				fp.write((char*)this,sizeof(*this));
				b.updateStatusbyID(bid,"issued");
				fp.close();
				cout<<"book issued\n";
			}
			else
			{
				cout<<"sutdnet doesn't exit";
				issueBook();
			}
		}
		else
		{
			cout<<"book is already issues to someone else";
			issueBook();
		}
		
	}
	else
	{
		cout<<"book doesn't exist";
		issueBook();
	}
	
}
void Transaction::showIssuedBookbySid(int sid){
fstream fp;
Transaction t;
fp.open(TName,ios::in);
while( (fp.read((char*)&t,sizeof(t))) != NULL ){
	if(t.sid==sid&&strcmp(t.rdate,"pending")==0)
	{
		cout<<t.tid<<t.bid<<endl;
	}

}

}

void Transaction::returnBook(){
	cout<<"enter sid";
	cin>>sid;
	showIssuedBookbySid(sid);
	cout<<"enter book id";
	cin>>bid;
	fflush(stdin);
	cout<<"enter return date";
	cin>>rdate;
	
	
	
	
	int flag=0;
	int pos;
	fstream f;
    Transaction t ;
    pos = sizeof(t);
    pos =pos*(-1);
    f.open(TName,ios::in|ios::out);
    while( (f.read((char*)&t,sizeof(t))) != NULL )
	{
   		if(t.sid==sid&&t.bid==bid&&strcmp(t.rdate,"pending")==0)
		{
		    f.seekp(pos,ios::cur);
		   	strcpy(t.rdate,rdate);
		    
		    f.write( (char *) &t, sizeof(t) );
		    flag=1;
		   	break;
		}
	}
	if(flag==0)
		cout<<"\n record not found"<<endl;
	else
	cout<<"book returned";
}

