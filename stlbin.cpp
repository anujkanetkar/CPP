#include <iostream> 
#include <stack>

using namespace std;

stack <int> read();
stack <int> add(stack <int> &, stack <int> &);
stack <int> display(stack <int>);
 
int main()
{
	stack <int> s1, s2, s3;
	int b;
	char ch = 'y';

	s1 = read();

	s2 = read();
	
	cout << "Addition is: ";
	s3 = add(s1, s2);  
	 
	display(s3);
	
	return 0;
}

stack <int> display(stack <int> s)
{
	while(!s.empty())
	{
		cout << s.top();
		s.pop(); 
	}
}

stack <int> read()
{
	stack <int> s;
	int n, x;
	cout << "Enter no of bits" << endl;
	cin >> n; 
	
	cout << "Enter binary number" << endl;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		s.push(x);
	}
	
	return s;
}

stack <int> add(stack <int> &s1, stack <int> &s2)
{
	stack <int> s;
	int carry = 0;
	int b1, b2, sum;
	
	while(!s1.empty() || !s2.empty())
	{
		b1 = b2 = 0;
		if(!s1.empty())
		{
			b1 = s1.top();
			s1.pop();	
		}
		
		if(!s2.empty())
		{
			b2 = s2.top();
			s2.pop();
		}

		sum = (b1 + b2 + carry) % 2;
		carry = (b1 + b2 + carry) / 2;
		s.push(sum);
	}

	if(carry == 1)
	{
		s.push(1);
	}

	return s;
}


