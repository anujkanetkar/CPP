#include <iostream>

using namespace std;

#define MAX 5
class queue
{
	private:
		int front, rear;
		int a[MAX];
		
	
	public:
		queue()
		{
			front = rear = -1;
		}

		bool isEmpty()
		{
			if(rear = -1)
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
	queue q;


	if( !q.isEmpty() )
		q.del();
	else
		cout << "Queue is empty" << endl;

	if( !q.isFull() )
		q.add(10);
	else 
		cout << "Queue is full" << endl;

	  if( !q.isFull() )
                q.add(20);
        else
                cout << "Queue is full" << endl;

	  if( !q.isFull() )
                q.add(30);
        else
                cout << "Queue is full" << endl;

	  if( !q.isFull() )
                q.add(40);
        else
                cout << "Queue is full" << endl;

	  if( !q.isFull() )
                q.add(50);
        else
                cout << "Queue is full" << endl;

	  if( !q.isFull() )
                q.add(60);
        else
                cout << "Queue is full" << endl ;

	 if( !q.isEmpty() )
                q.del();
        else
                cout << "Queue is empty" << endl;

	 if( !q.isEmpty() )
                q.del();
        else
                cout << "Queue is empty" << endl;

	 if( !q.isEmpty() )
                q.del();
        else
                cout << "Queue is empty" << endl;

	 if( !q.isEmpty() )
                q.del();
        else
                cout << "Queue is empty" << endl;

	 if( !q.isEmpty() )
                q.del();
        else
                cout << "Queue is empty" << endl;


	 if( !q.isEmpty() )
                q.del();
        else
                cout << "Queue is empty" << endl;

}
