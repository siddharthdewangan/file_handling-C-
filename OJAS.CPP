//To create OJAS database...
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
class ojas
{
	char name[50],clg[50],cont[11];
	char sem[3],sparx[3],foj[3];

	public:
		void get()
		{
			cout<<"\nEnter The Participants Name:  ";
			gets(name);
			cout<<"\nEnter The College Name:  ";
			gets(clg);
			cout<<"\nEnter Your Contact Number:  ";
			gets(cont);
			cout<<"\nEnter Your Semester:  ";
			cin>>sem;
			cout<<"\nThe List Of Events Are:  (Enter y/n for Each)";
			cout<<"\nSPARKS : ";
			cin>>sparx;
			cout<<"\nFACE OF OJAS : ";
			cin>>foj;
		 }
		 void display()
		 {
		       cout<<"\n\n"<<setw(20)<<setiosflags(ios::left)<<name<<setw(10)<<setiosflags(ios::left)<<clg<<setw(12)<<setiosflags(ios::left)<<cont<<setw(10)<<setiosflags(ios::left)<<sem<<setw(10)<<setiosflags(ios::left)<<sparx<<setw(10)<<setiosflags(ios::left)<<foj;

		 }
		 int compare(char[]);

};

int ojas::compare(char n[])
    {
      return strcmp(n,name);
    }
int main()
{
	int c;
	char v[50],s;
	clrscr();
	fstream f("ojas.txt",ios::in|ios::out|ios::ate|ios::binary);
	if(!f)
	{
		cout<<"UNABLE TO OPEN FILE";
		return 0;
	}
	while(1)
	{ clrscr();
	cout<<"\n\t\t***********WELCOME TO OJAS***********";
	cout<<"\n\t\t1.Add a participant.";
	cout<<"\n\t\t2.Search a participant by name.";
	cout<<"\n\t\t3.Display all participants.";
	cout<<"\n\t\t4.Display participants by particular event";
	cout<<"\n\t\t5.Remove a particular participant";
	cout<<"\n\t\t6.Update informtion by your name";
	cout<<"\n\t\t7.EXIT.";
	cout<<"\n\t\tEnter your choice... ";
	cin>>c;
	switch(c)
	{
		case 1://add a participant

			clrscr();
			ojas o;
			o.get();
			f.clear();

		       f.write((char *)&o,sizeof(o));
			break;
		case 2:  //search by name
  clrscr();
  f.clear();
  char n[40];
  cout<<endl<<"Enter The Name To Be Searched : ";
  cin.ignore(32767,'\n');
  cin.getline(n,40);
  f.seekg(0);
  cout<<"\n\n"<<setw(20)<<setiosflags(ios::left)<<"name"<<setw(10)<<setiosflags(ios::left)<<"college"<<setw(12)<<setiosflags(ios::left)<<"contact"<<setw(10)<<setiosflags(ios::left)<<"semester"<<setw(10)<<setiosflags(ios::left)<<"sparx"<<setw(10)<<setiosflags(ios::left)<<"foj";
  while(f)
  {
   f.read((char*)&o,sizeof(o));
   if(!o.compare(n))
   {
    o.display();
    break;
   }}
 break;
		case 3: //display all participants
			clrscr();
			char ch;
				f.clear();
				f.seekg(0);
			       cout<<"\n\n"<<setw(20)<<setiosflags(ios::left)<<"name"<<setw(10)<<setiosflags(ios::left)<<"college"<<setw(12)<<setiosflags(ios::left)<<"contact"<<setw(10)<<setiosflags(ios::left)<<"semester"<<setw(10)<<setiosflags(ios::left)<<"sparx"<<setw(10)<<setiosflags(ios::left)<<"foj";
			       while(f)
			       {
			       f.read((char *)&o,sizeof(o));

				if(f.eof()==0)
				{

				 o.display();
				}
			       }
			break;

		case 4: //search by foj
			clrscr();
			char che;
			cout<<"Enter The Event Name Whose List You Want To See : ";
			gets(v);
			cout<<"\n\n"<<setw(20)<<setiosflags(ios::left)<<"name"<<setw(10)<<setiosflags(ios::left)<<"college"<<setw(12)<<setiosflags(ios::left)<<"contact"<<setw(10)<<setiosflags(ios::left)<<"semester"<<setw(10)<<setiosflags(ios::left)<<"sparx"<<setw(10)<<setiosflags(ios::left)<<"foj";
			if(!strcmp(v,"foj"))
			{

				f.clear();
				f.seekg(117,ios::beg);

			       while(f)
			       {
			       f.get(che);
				if(che=='y')
				{
				 f.seekg(-118,ios::cur);
				 f.read((char *)&o,sizeof(o));
				 o.display();
				 f.seekg(117,ios::cur);
			       }
			       else
			       {
			       f.seekg(119,ios::cur);
				}
			       }
			       }

			       //search by sparx

			       if(!strcmp(v,"sparx"))
			{
				f.clear();
				f.seekg(114,ios::beg);
			       while(f)
			       {
			       f.get(che);
				if(che=='y')
				{
				 f.seekg(-115,ios::cur);
				 f.read((char *)&o,sizeof(o));
				 o.display();
				 f.seekg(114,ios::cur);
				}
			       else
			       {
			       f.seekg(119,ios::cur);
				}
			       }
			       }
			break;
		case 5: //remove a record
			clrscr();
			f.clear();
  char n2[40];
  int x;
  cout<<endl<<"Enter Name Whose Record Is To Be Removed : ";
  cin.ignore(32767,'\n');
  cin.getline(n2,40);
  f.seekg(0);
  fstream f1("ojas1.txt",ios::in|ios::out|ios::ate|ios::binary);
  while(f)
  {
   f.read((char*)&o,sizeof(o));
   if(!o.compare(n2))
   {
    f.seekg(-120,ios::cur);
    x=f.tellg();

    f.seekg(0);
    for(int i=1;i<=(x/120);i++)
    {
    f.read((char*)&o,sizeof(o));
    f1.write((char*)&o,sizeof(o));
    }
    break;
   }
  }
    f.seekg(120,ios::cur);
    while(f.eof()==0)
    {
    f.read((char*)&o,sizeof(o));
    if(f.eof()==0)
    f1.write((char*)&o,sizeof(o));
    }
    f.close();
    f.open("ojas.txt",ios::in|ios::out|ios::ate|ios::binary|ios::trunc);
    f1.seekg(0);
    while(f1)
    {
    f1.read((char*)&o,sizeof(o));
    if(f1.eof()==0)
    f.write((char*)&o,sizeof(o));
    }
    f1.close();
    remove("ojas1.txt");
    break;


		case 6: //update a record
		       clrscr();
		       f.clear();
  char n1[40];
  cout<<endl<<"Enter Name To Be Updated : ";
  cin.ignore(32767,'\n');
  cin.getline(n1,40);
  f.seekg(0);

  while(f)
  {
   f.read((char*)&o,sizeof(o));
   if(!o.compare(n1))
   {
    o.get();
    cout<<"The Updated Record Is:";
    cout<<"\n\n"<<setw(20)<<setiosflags(ios::left)<<"name"<<setw(10)<<setiosflags(ios::left)<<"college"<<setw(12)<<setiosflags(ios::left)<<"contact"<<setw(10)<<setiosflags(ios::left)<<"semester"<<setw(10)<<setiosflags(ios::left)<<"sparx"<<setw(10)<<setiosflags(ios::left)<<"foj";
    f.seekg(-120,ios::cur);
    f.write((char *)&o,sizeof(o));

    f.seekg(-120,ios::cur);
    f.read((char *)&o,sizeof(o));
    o.display();
    break;
   }}

			break;
		case 7:
			exit (0);
		default:
			cout<<"\nINVALID CHOICE";
			cout<<"\nPLEASE ENTER AGAIN";
			break;

    }
cout<<"\n\nDo you wanna continue (y/n) ? ";
cin>>s;
if(s=='n'||s=='N')
break;
}
//while(1);
getch();
return 0;

}

