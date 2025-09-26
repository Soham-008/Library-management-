#include<iostream>
#include<fstream>
#include<string.h>
#include"fine.cpp"
using namespace std;
class student
{
	public:
		char n[10],b[10],s[10];
		int y;
		int rollno;
		public:
			void sdetails(void)
			{
				cout<<"enter the name of d student"<<endl;
				cin>>n;
				cout<<"enter d branch of d student"<<endl;
				cin>>b;
				cout<<"enter the section of d student"<<endl;
				cin>>s;
				cout<<"enter the rollno of d student"<<endl;
				cin>>rollno;
			}
};
class item : virtual public student
{
	public:
		char title[10];
		char author[10];
		int libcode;
		public:
			void idetails(void)
			{
				cout<<"enter d title of d title"<<endl;
				cin>>title;
				cout<<"enter d name of d author"<<endl;
				cin>>author;
				cout<<"enter d code of d library"<<endl;
				cin>>libcode;
			}
};
class book : virtual public item
{
	public:
		int isbnno;
		public:
			void bdetails(void)
			{
				cout<<"enter d isbnno of the book"<<endl;
				cin>>isbnno;
			}
};
class journal : virtual public item
{
	public:
		int issnno;
		public:
			void jdetails(void)
			{
				cout<<"enter d issnno of the journal"<<endl;
				cin>>issnno;
			}
};
class fine1 : virtual public student
{
	public:
		int d1,m1,y1;
		int d2,m2,y2;
		public:
			 int fdetails(void)
			{
				cout<<"enter the date of issue"<<endl;
				cin>>d1;
				cout<<"enter the month of issue"<<endl;
				cin>>m1;
				cout<<"enter the year of issue"<<endl;
				cin>>y1;
				int re;
				if(re=2)
				{
				cout<<"enter the date of return"<<endl;
				cin>>d2;
				cout<<"enter the month of return"<<endl;
				cin>>m2;
				cout<<"enter the year of return"<<endl;
				cin>>y2;
				int f1;
				Date dt1={d1,m1,y1};
				Date dt2={d2,m2,y2};
				cout<<"the difference b/w d two dates is"<<getDifference(dt1,dt2);
				f1=getDifference(dt1,dt2);
				int fine;
				}
			}
};
class international : public journal,public book,public fine1
{
	public:
		void internationaldisplay(void)
		{
			cout<<"the included contents of d file are"<<endl;
			cout<<n<<"\t"<<b<<"\t"<<s<<"\t"<<y<<"\t"<<rollno<<"\t"<<title<<"\t"<<author<<"\t"<<libcode<<"\t";
		}
		friend class national;
};
class national : public journal,public book,public fine1
{
	public:
		int d,m;
		char* a[10];
		char* b[10];
		char* c[10];
		void nationaldisplay(international & inter)
		{
			a[10]=inter.n;
			b[10]=inter.b;
			c[10]=inter.s;
			d=inter.y;
			m=inter.rollno;
			cout<<"the included contents of d file are"<<endl;
			cout<<d<<"\t"<<m<<"\t"<<a[10]<<"\t"<<b[10]<<"\t"<<c[10]<<"\t"<<title<<"\t"<<author<<"\t"<<libcode<<"\t";
		}
};
int main()
{
	char q[]="international";
	char x[]="national";
	char e[]="journal";
	char o[]="book";
	char d[20];
	international it;
	national nt;
	int z;
	cout<<"enter d no of items u wanted 2 take:"<<endl;
	cin>>z;
	char p[20];
	fstream inoutf;
	cout<<"enter d value of limit"<<endl;
	int y;
	cin>>y;
	int h;
	int i;
	int fine;
inoutf.open("dinesh.txt",ios::out|ios::in);
	for(int i=0;i<y;i++)
	{
		
		it.sdetails();
		int tf=0;
		for(int j=0;j<z;j++)
		{
			inoutf.open("dinesh.txt",ios::out|ios::in);
			cout<<"enter journal or book"<<endl;
			cin>>d;
			cout<<"enter international or national"<<endl;
			cin>>p;
			if(strcpy(d,e)==0)
			{
				if(strcpy(q,p)==0)
				
				{
					it.idetails();
					it.jdetails();
					
					int f=it.fdetails();
					
					inoutf.write((char*) & it,sizeof(it));
					if(f<=15)
					{
						fine=0;
						cout<<endl<<"no fine"<<endl;
						inoutf<<fine;
					}
					else{
						fine=f-15;
						cout<<"fine is"<<fine;
						inoutf<<fine;
					}
					inoutf.read((char*)&it,sizeof(it));
					inoutf>>fine;
					it.internationaldisplay();
					cout<<fine;
					tf=tf+fine;
				}
				else if(strcpy(x,p)==0)
					{
					nt.idetails();
					nt.jdetails();
					
					int f=nt.fdetails();
					
					inoutf.write((char*) & nt,sizeof(nt));
					if(f<=15)
					{
						fine=0;
						cout<<endl<<"no fine"<<endl;
						inoutf<<fine;
					}
					else{
						fine=f-15;
						cout<<"fine is"<<fine;
						inoutf<<fine;
					}
					inoutf.read((char*)&nt,sizeof(nt));
					inoutf>>fine;
					nt.nationaldisplay(it);
					cout<<fine;
					tf=tf+fine;
				}
				else
				{
					cout<<"the data u have entered is incorrect or  not available"<<endl;
				}
				
			}
				else if(strcpy(d,o)==0)
				{
				if(strcpy(q,p)==0)
				
				{
					it.idetails();
					it.bdetails();
					
					int f=it.fdetails();
					
					inoutf.write((char*)&it,sizeof(it));
					if(f<=15)
					{
						fine=0;
						cout<<endl<<"no fine"<<endl;
						inoutf<<fine;
					}
					else{
						fine=f-15;
						cout<<"fine is"<<fine;
						inoutf<<fine;
					}
					inoutf.read((char*)&it,sizeof(it));
					inoutf>>fine;
					it.internationaldisplay();
					cout<<fine;
					tf=tf+fine;
				}
				else if(strcpy(x,p)==0)
					{
					nt.idetails();
					nt.bdetails();
					
					int f=nt.fdetails();
					
					inoutf.write((char*)&nt,sizeof(nt));
					if(f<=15)
					{
						fine=0;
						cout<<endl<<"no fine"<<endl;
						inoutf<<fine;
					}
					else{
						fine=f-15;
						cout<<"fine is"<<fine;
						inoutf<<fine;
					}
					inoutf.read((char*)&nt,sizeof(nt));
					inoutf>>fine;
					nt.nationaldisplay(it);
					cout<<fine;
					tf=tf+fine;
				}
				else
				{
					cout<<"the data u have entered is incorrect or  not available"<<endl;
				}
				cout<<"total fine is"<<tf;
			
			}
			else
			{
				cout<<"you have entered the one which is not available"<<endl;
			}
			cout<<endl;
		inoutf.close();
	}
}
	return 0;
}


	


