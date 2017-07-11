#include <iostream>

using namespace std;

const int MAX = 5;

class Queue
{
	private:
		int front, rear;
		int a[MAX];		
	public:
		Queue()
		{
			front = rear = -1;
		}

		bool isEmpty()
		{
			if(rear == -1)
				return true;
			else 
				return false;
		}
		
		bool isFull()
		{
			if(rear == MAX-1)
				return true;
			else 
				return false;
		}

		void add(int n)
		{
			rear++;
			a[rear] = n;
			if(front ==  -1)
				front = 0;
		}	

		int del()
		{
			int n = a[front];
			if(front == rear)
				front = rear = -1;
			else
				front++;
			return n;
		}	

};


int main()
{
	Queue q;
	int num;

	if( !q.isEmpty() )
	{
		num = q.del();
		cout << "The deleted number is: " << num << endl;
	}
	else
		cout << "Queue is empty" << endl;

	if( !q.isFull() )
	{
		q.add(10);
		cout << "The number added is 10" << endl;
	}
	else 
		cout << "Queue is full" << endl;

	if( !q.isFull() )
        {
		q.add(20);
		cout << "The number added is 20" << endl;
	}
		

        else	
                cout << "Queue is full" << endl;

	if( !q.isFull() )
	{
          	q.add(30);
		cout << "The number added is 30" << endl;

	}
        else
                cout << "Queue is full" << endl;

	if( !q.isFull() )
	{
                q.add(40);
		cout << "The number added is 40" << endl;
	}
        else
                cout << "Queue is full" << endl;

	if( !q.isFull() )
	{
                q.add(50);
		cout << "The number added is 50" << endl;
	}
        else
                cout << "Queue is full" << endl;

	if( !q.isFull() )
	{
                q.add(60);
		cout << "The number added is 10" << endl;
	}
        else
                cout << "Queue is full" << endl ;

	if( !q.isEmpty() )
	{
                num = q.del();
		cout << "The deleted number is: " << num << endl;
	}
        else
                cout << "Queue is empty" << endl;

	if( !q.isEmpty() )
        {
		num = q.del();
                cout << "The deleted number is: " << num << endl;		
	}
        else
                cout << "Queue is empty" << endl;

	if( !q.isEmpty() )
	{
		num = q.del();
                cout << "The deleted number is: " << num << endl;	
        }
        else
                cout << "Queue is empty" << endl;

	if( !q.isEmpty() )
        {
		num = q.del();
                cout << "The deleted number is: " << num << endl;
	}	
        else
                cout << "Queue is empty" << endl;

	if( !q.isEmpty() )
        {
		num = q.del();
                cout << "The deleted number is: " << num << endl;
	}
        else
                cout << "Queue is empty" << endl;


	if( !q.isEmpty() )
        {
		num = q.del();
                cout << "The deleted number is: " << num << endl;
	}
        else
                cout << "Queue is empty" << endl;

}
