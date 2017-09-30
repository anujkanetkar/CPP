#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Person
{
	private:
		string name;
		string dob;
		string telno;
	public:
		Person()
		{
			name = dob = telno = "";
		}

		Person(string s)
		{
			name = s;
		}

		void getinfo();
		void display();
		void setname(string);

	friend bool operator < (const Person&, const Person&);
	friend bool operator == (const Person&, const Person&);
};

void Person :: getinfo()
{
	cout << "Enter name" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter birth date" << endl;
	cin.ignore();
	cin >> dob;
	cout << "Enter telephone no." << endl;
	cin.ignore();
	cin >> telno;
}

void Person :: setname(string s)
{
	name = s;
	dob = telno = "";
}

void Person :: display()
{
	cout << name << "\t" << dob  << "\t" << telno << endl;
}

bool operator < (const Person &p1, const Person &p2)
{
	return(p1.name < p2.name);
}

bool operator == (const Person &p1, const Person &p2)
{
	return(p1.name == p2.name) ? true : false;
}

class Item
{
	private:
		int code;
		string it_name;
		int qty;
		float cost;
	public:
		Item()
		{
			code = qty = 0;
			cost = 0.0;
			it_name = "";
		}

		void getqty(string);
		void display();
		void getinfo();
	
	friend bool operator == (const Item&, const Item&);
	friend bool operator < (const Item&, const Item&);
};

void Item :: getqty(string s)
{
	it_name = s;
	code = qty = 0;
	cost = 0.0;
}

void Item :: getinfo()
{
	cout << "Enter coded" << endl;
	cin >> code; 
	cout << "Enter name" << endl;
	cin >> it_name;
	cout << "Enter quantity" << endl;
	cin >> qty;
	cout << "Enter cost" << endl;
	cin >> cost;  
}

void Item :: display()
{
	cout << code << "\t" << it_name << "\t" << qty << "\t" << cost << endl;
}

bool operator == (const Item &i1, const Item &i2)
{
	return(i1.it_name == i2.it_name) ? true : false;
}

bool operator < (const Item &i1, const Item &i2)
{
	return(i1.it_name < i2.it_name);
}

int main()
{
	list <Person> lp;
	list <Item> li;
	int choice;
	char ch = 'y';
	string pers_name, qt_name;

	Person p, p1;
	Item i, i1;
	
	while(ch == 'y')
	{
		p.getinfo();
		lp.push_back(p);
		cout << "Add another record? (y/n)" << endl;
		cin >> ch;
		
				/*list <Person> :: iterator ip = lp.begin();
				while(ip != lp.end())
				{
					ip -> display();
					ip++;
				}*/
	}

	while(true)
	{
		cout << "1. Sort Person record according to name" << endl;
		cout << "2. Search name of person" << endl;

		cout << "Enter choice" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
				lp.sort();
				list <Person> :: iterator ip = lp.begin();
				while(ip != lp.end())
				{
					ip -> display();
					ip++;
				}
				break;
			case 2:
				cout << "Enter name to be searched" << endl;
				cin.ignore();
				getline(cin, pers_name);
				p1.setname(pers_name);
				list <Person> :: iterator ip1;
				ip1 = find(lp.begin(), lp.end(), p1);
				
				if(ip1 != lp.end())
				{
					ip1 -> display();
				}
		}
	}

	
	while(ch == 'y')
	{
		i.getinfo();
		li.push_back(i);
		cout << "Add another record? (y/n)" << endl;
		cin >> ch;
	}

	while(true)
	{
		cout << "1. Sort Item according to code" << endl;
		cout << "2. Search item according to name" << endl;

		cout << "Enter choice" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
				li.sort();
				list <Item> :: iterator ii = li.begin();
				while(ii != li.end())
				{
					ii -> display();
					ii++;
				}
				break;
			case 2:
				cout << "Enter quantity to be searched" << endl; 
				cin >> qt_name;
				i1.getqty(qt_name);
				list <Item> :: iterator ii1;
				ii1 = find(li.begin(), li.end(), i1);
				if(ii1 != li.end())
				{
					ii1 -> display();
				} 
				break;	
		}  
	}
}

