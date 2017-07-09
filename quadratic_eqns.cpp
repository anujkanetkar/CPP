#include <iostream>
#include <cmath>

using namespace std;

class Quadratic
{
	private:
		int a,b,c;
	public:
		Quadratic()
		{
			a = b = c = 0;
		}
		
		Quadratic operator+(Quadratic q)
		{
			Quadratic t;
			t.a = a + q.a;
			t.b = b + q.b;
			t.c = c + q.c;
			return t;
		}
		int polyget()
		{
			int x;
			cout << "Enter the value of x to find the value of the polynomial" << endl;
			cin >> x;
			return x;
		}
		int eval(int x)
		{
			int val;
			val = a*x*x + b*x + c;
			return val;
		}
		void solutions()
		{
			float r1,r2;
			float d;
			d = b*b - 4*a*c;
			if(d < 0)
				cout << "Imaginary roots" << endl;
			else if(d == 0)
			{
				r1 = (0 - b)/(2.0 * a);
				cout << "Equal roots are " << r1 << "and " << r1 << endl;	
			}
			else
			{
				r1 = (0 - b + sqrt(d))/(2 * a);
				r2 = (0 - b - sqrt(d))/(2 * a);
				cout << "Real and distinct roots are " << r1 << " and " << r2 << endl;
			}

		}
		
		void display(int v)
		{
			cout << "Value of polynomial for entered value of x " << " is " << v << endl;
		}
		
		friend istream& operator>>(istream&, Quadratic&);
		friend ostream& operator<<(ostream&, Quadratic);
};

istream& operator>>(istream &x, Quadratic &q)
{
	cout << "Enter the coefficients of the quadratic polynomial: " << endl;
	x >> q.a >> q.b >> q.c;
}

ostream& operator<<(ostream &x, Quadratic q)
{
	x << q.a << "x^2 + " << q.b << "x + " << q.c << endl; 
}
int main()
{
	Quadratic q1, q2;
	cin >> q1;
	cout << q1;
	cin >> q2;
	cout << q2;
	Quadratic q;
	q = q1 + q2;
	cout << "The quadratic polynomial after addition is: " << q;
	Quadratic qval;
	cin >> qval;
	cout << "The polynomial as a function of x is: " << qval;
	int x = qval.polyget();
	int value = qval.eval(x);
	q.display(value);
	Quadratic qsol;
	cin >> qsol;
	cout << qsol;
	qsol.solutions();
}

