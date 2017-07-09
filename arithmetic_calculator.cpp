#include <iostream>

using namespace std;

class arithmetic
{
	private:
		int n1,n2;
		char ch,c;
	public:
		arithmetic()
		{
			n1=0; n2=0;
		}
		void calc()
		{
			while(1)
			{
				cout << "Enter first operand, operator and second operand: " << endl;
				cin >> n1 >> ch >> n2;
	
				switch(ch)
				{
					case '+':
						cout << n1 << "+" << n2 << "=" << n1+n2 << endl;
						break;
					case '-':
						cout << n1 << "-" << n2 << "=" << n1-n2 << endl;
						break;
					case '*':
						cout << n1 << "*" << n2 << "=" << n1*n2 << endl;
						break;
					case '/':
						cout << n1 << "/" << n2 << "=" << n1/n2 << endl;
						break;
					case '%':
						cout << n1 << "%" << n2 << "=" << n1%n2 << endl;
						break;
					default:
						cout << "Invalid character entered" << endl;
				}
				cout << "Do another? (y/n)" << endl;
				cin >> c;
				if(c == 'y')
					continue;
				else
					break;
			}	
		}	
};

int main()
{
	arithmetic a;
	a.calc();
	return 0;
}
