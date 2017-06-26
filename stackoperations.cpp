#include <iostream>
using namespace std;
#define MAX 5

class stack
{
	private:
		int top;
		int a[MAX];
		
		
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

		bool isEmpty()
		{
			if(top == -1)
				return true;
			else
				return false;
		}

		bool isFull()
		{
			if(top == MAX-1)
				return true;
			else
				return false;		
		}

};

int main()
{
	stack s;
	
	if( !s.isFull() )
		s.push(10);
	else
		cout << "Stack is full" << endl;
	
	 if( !s.isFull() )
                s.push(20);
        else
                cout << "Stack is full" << endl;

	 if( !s.isFull() )
                s.push(30);
        else
                cout << "Stack is full" << endl;

	 if( !s.isFull() )
                s.push(40);
        else
                cout << "Stack is full" << endl;
	
	 if( !s.isFull() )
                s.push(50);
        else
                cout << "Stack is full" << endl;

	 if( !s.isFull() )
                s.push(60);
        else
                cout << "Stack is full" << endl;

	if( !s.isEmpty() )
		s.pop();
	else
		cout << "Stack is empty" << endl;

	 if( !s.isEmpty() )
                s.pop();
        else
                cout << "Stack is empty" << endl;

	 if( !s.isEmpty() )
                s.pop();
        else
                cout << "Stack is empty" << endl;

	 if( !s.isEmpty() )
                s.pop();
        else
                cout << "Stack is empty" << endl;

	 if( !s.isEmpty() )
                s.pop();
        else
                cout << "Stack is empty" << endl;

	 if( !s.isEmpty() )
                s.pop();
        else
                cout << "Stack is empty" << endl;

}
