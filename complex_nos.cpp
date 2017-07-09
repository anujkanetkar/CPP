#include <iostream>

using namespace std;

class Complex
{
	private:
		int r,i;
	public:
		Complex()
		{
			r = 0;
			i = 0;
		}
		
		void show()
		{
			cout << "The entered complex number is " << r << " + " << i << "i" << endl;
		}
		Complex operator+(Complex x)
		{
			Complex t;
			t.r = r + x.r;
			t.i = i + x.i;
			return t;			
		}
		Complex operator*(Complex x)
		{
			Complex t;
			t.r = r * x.r - i * x.i;
			t.i = r * x.i + i * x.r;
			return t;
		}

		friend istream& operator>>(istream&, Complex&);
		friend ostream& operator<<(ostream&, Complex);
};

istream& operator>>(istream &x, Complex &c)
{
	cout << "Enter the real and imaginary part of the complex number: " << endl;
	x >> c.r >> c.i;
	return x;
}

ostream& operator<<(ostream &x, Complex c)
{
	x << c.r << " + " << c.i << "i" << endl;
	return x;	
}

int main()
{
	Complex a;
	cin >> a;
	cout << "The entered complex number is: " << a;
	Complex b;
	cin >> b;
	cout << "The entered complex number is: " << b;
	Complex c;
	c = a + b;
	cout << "Addition of the complex numbers is: " << c;	
	c = a * b;
	cout << "Multiplication of the complex numbers is: " << c;
}

