#include <iostream>

using namespace std;

class myEx
{
	public:
		string str ;
	public:
		myEx(string s)
		{
			str =s ;
		}
};


int main()
{
	int age;
	float inc;	
	string city, error;
	bool vehicle;	
	
	try
	{
		cout << "Enter age" << endl;
		cin >> age;
		if(age < 18 || age > 55)
		{
			error = "Invalid age" ;
			myEx e ( error ) ;
			throw e ;
		}
		else
		{
			cout << "Age: " << age << endl;
		}

		cout << "Enter income per month" << endl;
		cin >> inc;
		if(inc < 50000 || inc > 100000)
		{
			error = "Invalid income";
			myEx e ( error ) ;
			throw e ;
		}
		else
		{
			cout << "Income: " << inc << endl;
		}

		cout << "Enter city of residence" << endl;
		cin >> city;
		if((city.compare("Pune") != 0) && (city.compare("Mumbai") != 0) && (city.compare("Bangalore") != 0) && (city.compare("Chennai") != 0))
		{
			error = "City not allowed";
			myEx e ( error ) ;
			throw e ;
		}
		else
		{
			cout << "City: " << city << endl;
		}

		cout << "Enter 1 for 4 wheeler vehicle or 0 for any other type of vehicle" << endl;
		cin >> vehicle;
		if(vehicle != 1)
		{
			error = "Only 4 wheeler allowed";
			myEx e(error);
			throw e;
		}
		else
		{
			cout << "4 wheeler" << endl;
		}
	}

	catch(myEx e)
	{
		cout << e.str << endl;
	}
}
