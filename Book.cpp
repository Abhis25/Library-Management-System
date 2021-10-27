using namespace std;
#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#define BName "books.txt"
class Book{
	int bid;
	char bname[40],author[40],subject[40],publication[40];
	int price;
	char status[20];
	public:
		bool bookExist(int);
		char* getStatus(int);
		void getBook();
		void showBook();
		int getLatestID();
		void writeBook();
		void readBook();
		void readBookbyAuthor();
		void readBookbySubject();
		void readBookbyBid();	
		void readBookbyPublication();
		void readBookbyStatus();
		void updateBookName();
		void updateStatusbyID(int,char*);
		void DeleteBook();
		void menu();
};
		
		bool Book::bookExist(int bid){
			fstream f;
			Book b;
			f.open(BName,ios::in);
			int flag=0;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.bid==bid){
				
				flag=1;
				break;
			}
			}
		if(flag==1)
		return true;
		else
		return false;
		}
		
		char* Book::getStatus(int bid){
			fstream f;
			Book b;
			f.open(BName,ios::in);
			int flag=0;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.bid==bid){
					return b.status;	
			}
			}
		}
		
		void Book::getBook(){
			fflush(stdin);
			cout<<"\nEnter Book Name -> ";
			gets(bname);
			cout<<"\nEnter Book Author Name -> ";
			gets(author);
			cout<<"\nEnter Book Subject -> ";
			gets(subject);
			cout<<"\n Enter Book Publication -> ";
			gets(publication);
			cout<<"\n Enter Book Price -> ";
			cin>>price;
			strcpy(status,"available ");
		}
		
		void Book::showBook(){
			cout<<"\nName :"<<bname;
			cout<<"\nAuthor :"<<author;
			cout<<"\nSubject :"<<subject;
			cout<<"\nPublication :"<<publication;			
			cout<<"\nPrice :"<<price;
			cout<<"\nStatus :"<<status;	
			cout<<"\n***************************************"<<endl;		
		}
		
		int Book::getLatestID(){
			fstream f;
			Book b;
			f.open(BName,ios::in);
			int max=0;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.bid>max)
				max=b.bid;
			}
		return(max+1);
		}
		
		void Book::writeBook(){
				fstream f;
				f.open(BName,ios::app);
				this->getBook();
				this->bid=this->getLatestID();
				f.write((char*)this,sizeof(*this));
				cout<<"Book Inserted "<<endl;;
				f.close();
			}
		
		void Book::readBook(){
				fstream f;
				Book b;
				f.open(BName,ios::in);
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				b.showBook();
			}
				
				f.close();
			}
			
		void Book::readBookbyAuthor(){
				char aname[40];
				fstream f;
				Book b;
				f.open(BName,ios::in);
				cout<<"enter author name";
				cin>>aname;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(strcmp(aname,b.author)==0){
				
				
				b.showBook();
			
				}
			
			}
				
				f.close();
			}
		void Book::readBookbySubject(){
				char asubject[40];
				fstream f;
				Book b;
				f.open(BName,ios::in);
				cout<<"enter subject name";
				cin>>asubject;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(strcmp(asubject,b.subject)==0){
				
				
				b.showBook();
				}
			
			}
				
				f.close();
			}
		void Book::readBookbyBid(){
				int bid;
				fstream f;
				Book b;
				f.open(BName,ios::in);
				cout<<"enter Book id";
				cin>>bid;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(bid==b.bid){
				
				
				b.showBook();
				}
			
			}
				
				f.close();
			}

		void Book::readBookbyPublication(){
				char apublication[40];
				fstream f;
				Book b;
				f.open(BName,ios::in);
				cout<<"enter publication name";
				cin>>apublication;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(strcmp(apublication,b.publication)==0){
				
				
				b.showBook();
				}
			
			}
				
				f.close();
			}
			
		void Book::readBookbyStatus(){
				char astatus[40];
				fstream f;
				Book b;
				f.open(BName,ios::in);
				cout<<"enter status";
				cin>>astatus;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(strcmp(astatus,b.status)==0){
				
				
				b.showBook();
				}
				else{
					cout<<"not available"<<endl;
				}
			
			}
				
				f.close();
			}
	
		void Book::updateBookName(){
			int flag=0;
			int bid,pos;
			fflush(stdin);
			cout<<"\n Enter bid"<<endl;
			cin>>bid;
			fstream f;
    		Book b ;
   			 pos = sizeof(b);
    		pos =pos*(-1);
    		f.open("books.txt",ios::in|ios::out);
    		while( (f.read((char*)&b,sizeof(b))) != NULL )
				{
   					if(b.bid==bid)
					{
		 			   f.seekp(pos,ios::cur);
		    			fflush(stdin);
		    
						cout<<"\n Enter   bid."<<endl;
						this->getLatestID();
						fflush(stdin);
						cout<<"\nEnter New name."<<endl;
						gets(b.bname);
		  			  f.write( (char *) &b, sizeof(b) );
					    cout<<"\n books "<<b.getLatestID()<<"is updated successfully"<<endl;
		   				flag=1;
		   				break;
					}
				}
						if(flag==0)
						cout<<"\n book not found"<<endl;
}
	
	void Book::updateStatusbyID(int bid,char* status){
	int flag=0;
	int pos;
	fstream f;
    Book b ;
    pos = sizeof(b);
    pos =pos*(-1);
    f.open("books.txt",ios::in|ios::out);
    while( (f.read((char*)&b,sizeof(b))) != NULL )
	{
   		if(b.bid==bid)
		{
		    f.seekp(pos,ios::cur);
		    
		    strcpy(b.status,status);
			f.write( (char *) &b, sizeof(b) );
		    
		   	
		   	break;
		}
	}

}
void Book::DeleteBook(){
     Book b;
	int id;
	fflush(stdin);
	cout<<"\n enter book id which you want to delete"<<endl;
	cin>>id;
	fstream fp;
	fp.open(BName,ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&b,sizeof(b)))
	{
	 	if(b.bid!=id)
		{
			fp2.write((char*)&b,sizeof(b));
		}
	}
    fp2.close();
    fp.close();
    remove(BName);
    rename("Temp.txt",BName);
    cout<<"\n\nRecord Deleted ..";
}
	void Book::menu(){
	int x;
	char choice;
	 do{
	cout<<"enter 1 for write book"<<endl;
	cout<<"enter 2 for read book data"<<endl;
	cout<<"enter 3 for display book list"<<endl;
	cout<<"enter 4 for readBookBYAUTHOR"<<endl;
	cout<<"enter 5 for readBookbysubject "<<endl;
	cout<<"enter 6 for readBookbypublication "<<endl;
	cout<<"enter 7 for readBookbystatus "<<endl;
	cout<<"enter 8 for update book  "<<endl;
	cout<<"enter 9 for delete book  "<<endl;
    cin>>x;
    switch (x)
    {
    	case 1:
    		   writeBook();
    		break;
    		
    		case 2:
    		  readBook();
    		break;
    		
    		case 3:
    		  //displaystudentlist();
    		break;
    		
    		case 4:
    		  readBookbyAuthor();
    		break;
    		
    		case 5:
    		  readBookbySubject();
    		break;
    		
    	case 6:
    		  readBookbyPublication();
    		break;	
    		
    		case 7:
    		  readBookbyStatus();
    		break;
    		
    		case 8:
    		  updateBookName();
    		break;
    		
    		case 9:
    		  DeleteBook();
    		break;
    		default:
    			cout<<"invalid value"<<endl;
    			break;
	}
	cout<<"Do you want to perform more operations in Book Menu"<<endl;
	cin>>choice;
}while(choice=='y');
	
}			
