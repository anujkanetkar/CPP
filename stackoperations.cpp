#include <iostream>
using namespace std;

class stack
{
	private:
		int top;
		int a[5];
		static int TRUE;
		static int FALSE; 
		
	public:
		stack()
		{
			top = -1;
		}
			
		void push(int x)
		{
			top++;
			a[top] = x;
		}
		
		int pop()
		{
			int n = a[top];
			top--;
			return n;			
		}

		int isEmpty()
		{
			if(top == -1)
				return FALSE;
			else
				return TRUE;
		}

		int isFull()
		{
			if(top > 4)
				return FALSE;
			else
				return TRUE;		
		}

};

int stack::TRUE = 0;
int stack::FALSE = 1;

int main()
{
	stack s;
	
	if( !s.isFull() )
		s.push(10);
	else
		cout << "Stack is full" << endl;


	if( !s.isEmpty() )
		s.pop();
	else
		cout << "Stack is empty" << endl;
}
