#include <iostream> 
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include<vector>
#define CLEAR printf("\e[2J\e[H")//do not use semicolon

const short int MAX = 10;

using namespace std;

class Person
{ 
	private:
		char name[20];
		char sex;
		int age;
		char src[20];
		char des[20]; 
	public: 
		Person()
		{
			name[0] =  src[0] = des[0] = '\0';
			age = 0;
		}

		void update_journey();
		char* getname();
		char getsex();
		int getage();
		char* getsrc();
		char* getdes();
		void getinfo();
		void show();
		
};

void Person :: update_journey()
{
	cout << "Enter new departure station" << endl;
	cin >> src;
	cout << "Enter new arrival station" << endl;
	cin >> des; 
}

char* Person :: getname()
{
	return name;
}

char Person :: getsex()
{
	return sex;
}

int Person :: getage()
{
	return age;
} 

char* Person :: getsrc()
{
	return src;
}

char* Person :: getdes()
{
	return des;
}

void Person :: getinfo()
{
	cout << "Enter name" << endl;
	//cin.ignore();
	cin >> name; 
	cout << "Enter sex" << endl;
	//cin.ignore();
	cin >> sex;
	cout << "Enter age" << endl;
	//cin.ignore();
	cin >> age;
	cout << "Enter departure place" << endl;
	//cin.ignore();
	//cin.getline(src, 20);
	cin >> src;
	cout << "Enter arrival place" << endl;
	//cin.ignore();
	//cin.getline(des, 20);   
	cin >> des;
}

void Person :: show()
{
	cout << name << "\t" << sex << "\t" << age << "\t" << src << " to " << des << endl;
}	

class Filedata
{
	public:
		void display();
		bool display_record(char []);
		void add();
		bool update(char []);
		bool del(char []);
};

void Filedata :: display()
{	
	ifstream infile;
	Person p;
	infile.open("RESERVATION.DAT");
	infile.seekg(0);
	while(infile.read((char*)&p, sizeof(p)))
	{
		p.show();
	}
	infile.close();
}

bool Filedata :: display_record(char str[])
{
	ifstream infile;
	Person p;
	bool flag = false;
	infile.open("RESERVATION.DAT");

	while(infile.read((char*)&p, sizeof(p)))
	{
		if(strcmp(str, p.getname()) == 0)
		{
			cout << "Details" << endl;
			flag = true;
			p.show(); 
		}
	}

	infile.close();
	return flag;
}  

void Filedata :: add()
{
	Person p;
	ofstream outfile;
	outfile.open("RESERVATION.DAT", ios :: app);
	p.getinfo();
	outfile.write((char*)&p, sizeof(p));
	cout << "Tkt booked succesfully" << endl << endl; 
	outfile.close();
}

bool Filedata :: update(char str1[])
{
	Person p;
	bool flag = false;
	int pos;
	fstream f;
	f.open("RESERVATION.DAT", ios :: in | ios :: out);
	f.seekg(0);
	
	while(!f.eof())
	{
		f.read((char*)&p, sizeof(p));
		if(strcmp(str1, p.getname()) == 0)
		{
			cout << "Found" << endl << " Details" << endl;
			flag = true;
			p.show();
			pos = f.tellg();
			pos = pos - sizeof(Person);
			p.update_journey();
			f.seekp(pos);
			f.write((char*)&p, sizeof(p));
			break;	 
		}
	}
	
	f.close();
	
	return flag;
}

bool Filedata :: del(char str1[])
{
	Person p;
	char ch;
	bool flag = false;

	ifstream infile("RESERVATION.DAT", ios :: in);
	ofstream outfile("TEMP.DAT", ios :: out | ios :: app);
	
	while(!infile.eof())
	{
		infile.read((char*)&p, sizeof(p));
		if(strcmp(str1, p.getname()) == 0)
		{
			flag = true;
			p.show();
			cout << "Are you sure you want to delete this record? (y/n)" << endl;
			cin >> ch; 
			if(ch == 'n')
			{
				outfile.write((char*)&p, sizeof(p));
			}
		}
		else
		{
			outfile.write((char*)&p, sizeof(p));
		}
	}

	infile.close();
	outfile.close();
	
	remove("RESERVATION.DAT");
	rename("TEMP.DAT", "RESERVATION.DAT");

	return flag;	
		
}

class Admin
{
	private:
		char password[MAX];

	public:
		
		Admin();

		void checkpassword();

		void setpassword();

		void seedata();
};

Admin::Admin()
{
	 strcpy(password,"Admin1");
}

void Admin::checkpassword()
{
	CLEAR;

	cout << "\nEnter password\n";

	char bu[MAX];

	cin >> bu;

	int i=0;

	while(strcmp(bu,password))
	{

		i++;

		if(i==3)
			exit(1);

		cout << "\n\n-------AUTHENTICATION ERROR-------\n\n";

		cout << "You have " << 3-i << " chances left\n";

		cin >> bu;
	} 

}

void Admin :: setpassword()
{
	CLEAR;

	bool b;

	cout << "\nFor security reconfirm authentication\nEnter 1 to continue\n";
	
	cin >> b;

	checkpassword();

	cout << "\n\nEnter new password\n";

	cin >> password;

	cout << "Password successfully changed\nEnter 1 to continue\n";

	cin >> b;
}

void Admin :: seedata()
{	
	int chio=1;
	Filedata fd;
	char str[20];

	vector <string> names;
	ifstream infile;
	string word;
 
	bool b, check;

	while(chio<=3)
	{
		CLEAR;

		cout << "\nPress :\n1. Display all\n2. Display particular record\n3. Display sorted record\n4. Exit\n";

		cin >> chio;

		CLEAR;

		switch(chio)
		{
			case 1:
				fd.display();					
		
				cout << "Press 1. to continue" << endl; 
				cin >> b;
				
				break;

			case 2:
				cout << "Enter name" << endl;
				cin.getline(str, 20);
				
 				check = fd.display_record(str);
				if(check == false)
				{
					cout << "Not found" << endl; 
				}
	
				cout << "Press 1 to continue" << endl; 
				cin >> b;
				break;

			case 3:
				/*infile.open("RESERVATION.DAT");
				while(getline(infile, word))
				{
					names.push_back(word);
				}
				
				sort(names.begin(), names.end());

				for(size_t i=0; i<names.size(); i++)
				{
					cout << "names[i]"; 
				}*/
				cout << "Press 1 to continue" << endl; 
				cin >> b;

				break;
		}
	}
}


void intro()
{

	CLEAR;

	time_t t1,t2;

	t1 = time(0);

	t2 = t1;

	cout << "-------------------------------------------------------------------\n\n";

	cout << "		WELCOME TO RESERVATION SYSTEM\n\n";

	cout << "-------------------------------------------------------------------\n\n";

	while(t2-t1<5)
		t2 = time(0);

	CLEAR;
}

int main()
{
	int ch=1,ch2=1,ch3=1;

	bool w, check;
	char str[20];

	Admin a;
	//Person p;

	Filedata fd;

	intro();

	while(ch<=2)
	{

		CLEAR;

		cout << "MENU :\n1. Administration login\n2. Ticket booking\n3. Exit\n";

		cin >> ch;

		switch(ch)
		{
			case 1:
				a.checkpassword();
				CLEAR;
				while(ch2<=2)
				{
					cout << "\n\nPress :\n1. Setpassword\n2. See data\n3. Exit\n\n";

					cin >> ch2;

					if(ch2==1)
						a.setpassword();

					else if(ch2==2)
						a.seedata();
				}

				break;

			case 2:
				while(ch3<=3)
				{
					CLEAR;
					
					cout << "\n\nPress :\n1. Book ticket\n2. Change booking\n3. Cancel booking\n4. Exit\n\n";

					cin >> ch3;

					CLEAR;

					switch(ch3)
					{
						case 1:
							fd.add();
							cout << "Press 1 to continue" << endl;
							cin >> w;
							break;

						case 2:
							//update booking
							cout << "Enter name of passenger" << endl;
							cin.getline(str, 20); 
							check = fd.update(str);
							if(check == true)
							{
								cout << "Updated !!" << endl; 
							}
							else
							{
								cout << "Name not found in passenger list" << endl; 
							}
							cout << "Press 1 to continue" << endl; 
							cin >> w; 
							break;

						case 3:
							cout << "Cancel\nPres 1\n";
							cin >> w;
							//cancel booking
							cout << "Enter name of passenger" << endl;
							cin.getline(str, 20);	 
							check = fd.del(str);
							if(check == true)
							{
								cout << "Booking cancelled" << endl;
							}
							else
							{
								cout << "Booking not made" << endl; 
							}
							break;
					}

				} 
		}

	}

	return 0;
}		
	
