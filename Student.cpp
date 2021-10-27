using namespace std;
#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#define FILENAME "student.txt"
class students{
   int sid,mno;
    char name[40],standard[40];

public:
	bool studentExist(int);
	void showstudent();
void getstudent();
	int getLatestsID();
	void writestudent();
	void readstudent();
	void readstudentbyname();
	void readstudentbysstandard();
	void readstudentbysmobilenumber();
	void readstudentbysID();
	void readstudentbysID(int);
	void deletestudent();
	void updatestudentname();
	void menu();
};
	bool students::studentExist(int sid){
			fstream f;
			students b;
			f.open(FILENAME,ios::in);
			int flag=0;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.sid==sid){
				
				flag=1;
				break;
			}
			}
		if(flag==1)
		return true;
		else
		return false;
		}
   	void students::getstudent(){
    cout<<"\nEnter student Name  ";
     cin>>name;
    cout<<"\nEnter mobile no  ";
    cin>>mno;
    cout<<"\nEnter standard  ";
     cin>>standard;

}
void  students::showstudent(){
	   cout<<"\nNAME: "<<name;
	   cout<<"\nstudent id "<<sid;
       cout<<"\nmobile no: "<<mno;
       cout<<"\nstandard : "<<standard;

}
int students::getLatestsID(){
      fstream f;
     students b;
      f.open(FILENAME,ios::in);
      int max=0;

     while( (f.read((char*)&b,sizeof(b))) != NULL )
   {
        if(b.sid>max)
        max=b.sid;
   }
    return (max+1);
}
void students::writestudent(){
      fstream f;
      f.open(FILENAME,ios::app);
     this->getstudent();
     this->sid=this->getLatestsID();
     f.write((char*)this,sizeof(*this));
    cout<<"student Inserted";
    f.close();
}
void students::readstudent(){
         fstream f;
         students b;
          f.open(FILENAME,ios::in);

       while( (f.read((char*)&b,sizeof(b))) != NULL )
{
       b.showstudent();
}

        f.close();
}
void students::readstudentbyname(){
				char sname[40];
				int flag=0;
				fstream f;
				students b;
				f.open(FILENAME,ios::in);
				cout<<"enter students name to print";
				cin>>sname;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(strcmp(sname,b.name)==0){
				
				
				b.showstudent();
				flag=1;
				}
			
			}
				if(flag==0){
					cout<<"file not found";
				}
				f.close();
			}
	void students::readstudentbysstandard(){
				char sstandard[40];
				int flag=0;
				fstream f;
				students b;
				f.open(FILENAME,ios::in);
				cout<<"enter students standard to print";
				cin>>sstandard;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(strcmp(sstandard,b.standard)==0){
				
				
				b.showstudent();
				flag=1;
				}
			
			}
				if(flag==0){
					cout<<"file not found";
				}
				f.close();
			}
			void students::readstudentbysmobilenumber(){
			    int smno;
				int flag=0;
				fstream f;
				students b;
				f.open(FILENAME,ios::in);
				cout<<"enter students mobile number to print";
				cin>>smno;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.mno==smno){
				
				
				b.showstudent();
				flag=1;
				}
			
			}
				if(flag==0){
					cout<<"file not found";
				}
				f.close();
			}
			void students::readstudentbysID(){
			    int id;
				int flag=0;
				fstream f;
				students b;
				f.open(FILENAME,ios::in);
				cout<<"enter students id  to print";
				cin>>id;
			
			 while( (f.read((char*)&b,sizeof(b))) != NULL )
			{
				if(b.sid==id){
				
				
				b.showstudent();
				flag=1;
				}
			
			}
				if(flag==0){
					cout<<"file not found";
				}
				f.close();
			}
	void students::deletestudent()
{
	students b;
	int id;
	fflush(stdin);
	cout<<"\n Enter student no  which you want to delete"<<endl;
	cin>>id;
	fstream fp;
	fp.open(FILENAME,ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&b,sizeof(b)))
	{
	 	if(b.sid!=id)
		{
			fp2.write((char*)&b,sizeof(b));
		}
	}
    fp2.close();
    fp.close();
    remove(FILENAME);
    rename("Temp.txt",FILENAME);
    cout<<"\n\nRecord Deleted ..";
}
void students::updatestudentname(){
	int flag=0;
	int sid,pos;
	fflush(stdin);
	cout<<"\n Enter sid"<<endl;
	cin>>sid;
	fstream f;
    students b ;
    pos = sizeof(b);
    pos =pos*(-1);
    f.open(FILENAME,ios::in|ios::out);
    while( (f.read((char*)&b,sizeof(b))) != NULL )
	{
   		if(b.sid==sid)
		{
		    f.seekp(pos,ios::cur);
		    fflush(stdin);
		    
			cout<<"\n Enter   Sid."<<endl;
			this->getLatestsID();
			fflush(stdin);
			cout<<"\nEnter New name."<<endl;
			gets(b.name);
		    f.write( (char *) &b, sizeof(b) );
		    cout<<"\n student "<<b.getLatestsID()<<"is updated successfully"<<endl;
		   	flag=1;
		   	break;
		}
	}
	if(flag==0)
		cout<<"\n student not found"<<endl;
}
void students::menu(){
	int choice;
	char a;
	do{
	cout<<"enter 1 for write student data"<<endl;
	cout<<"enter 2 for read student data"<<endl;
	cout<<"enter 3 for display student list"<<endl;
	cout<<"enter 4 for search student sid"<<endl;
	cout<<"enter 5 for search student by sname "<<endl;
	cout<<"enter 6 for search student by smobile "<<endl;
	cout<<"enter 7 for search student by sstandard "<<endl;
	cout<<"enter 8 for update student  "<<endl;
	cout<<"enter 9 for delete student  "<<endl;
    cin>>choice;
    switch (choice)
    {
    	case 1:
    		 writestudent();
    		break;
    		
    		case 2:
    		 readstudent();
    		break;
    		
    		case 3:
    	//	 displaystudentlist();
    		break;
    		
    		case 4:
    		readstudentbysID();
    		break;
    		
    		case 5:
    readstudentbyname();
    		break;
    		
    	case 6:
    		 readstudentbysmobilenumber();
    		break;	
    		
    		case 7:
    		 readstudentbysstandard();
    		break;
    		
    		case 8:
    		 updatestudentname();
    		break;
    		
    		case 9:
    	 deletestudent();
    		break;
    		default:
    			cout<<"invalid value"<<endl;
    			break;
	}
	cout<<"\nDo you want to perform more operations in Student Menu"<<endl;
	cin>>a;
}while(a=='y');
fflush(stdin);
}
