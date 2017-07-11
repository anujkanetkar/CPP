#include <iostream>

using namespace std;

const int MAX = 5;

class Stack
{
	private:
		int top;
		int a[MAX];
	public:
		Stack()
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
	Stack s;
	int num;
	
	if( !s.isEmpty() )
	{
		num = s.pop();	
		cout << "The popped number is: " << num << endl;
	}
	else
		cout << "Stack is empty" << endl;
		
	if( !s.isFull() )
	{
		s.push(10);
		cout << "The number pushed is 10" << endl; 
	}
	else
		cout << "Stack is full" << endl;
	
	if( !s.isFull() )
	{
                s.push(20);
		cout << "The number pushed is 20" << endl;
	}
        else
                cout << "Stack is full" << endl;

	if( !s.isFull() )
	{
                s.push(30);
		cout << "The number pushed is 30" << endl;
	}
        else
                cout << "Stack is full" << endl;

	if( !s.isFull() )
	{
                s.push(40);
		cout << "The number pushed is 40" << endl;
	}
        else
                cout << "Stack is full" << endl;
	
	if( !s.isFull() )
	{
                s.push(50);
		cout << "The number pushed is 50" << endl;
	}
        else
                cout << "Stack is full" << endl;

	if( !s.isFull() )
	{
                s.push(60);
		cout << "The number pushed is 10" << endl;
	}
        else
                cout << "Stack is full" << endl;

	if( !s.isEmpty() )
	{
		num = s.pop();
		cout << "The popped number is: " << num << endl;
	}
	else
		cout << "Stack is empty" << endl;

	if( !s.isEmpty() )
	{
               num =  s.pop();
		cout << "The popped number is: " << num << endl;
	}
        else
                cout << "Stack is empty" << endl;

	if( !s.isEmpty() )
        { 
	  	num = s.pop();
		cout << "The popped number is: " << num << endl;
	}
        else
                cout << "Stack is empty" << endl;

	if( !s.isEmpty() )
	{
                num = s.pop();
		cout << "The popped number is: " << num << endl;
	}
        else
                cout << "Stack is empty" << endl;

	if( !s.isEmpty() )
	{
                num = s.pop();
		cout << "The popped number is: " << num << endl;
	}
        else
                cout << "Stack is empty" << endl;

	if( !s.isEmpty() )
	{
                num = s.pop();
		cout << "The popped number is: " << num << endl;
	}
        else
                cout << "Stack is empty" << endl;

}
