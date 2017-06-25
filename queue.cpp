#include <iostream>

using namespace std;

class queue
{
	private:
		int front, rear;
		int a[5];
		static int FALSE;
		static int TRUE;
	
	public:
		queue()
		{
			front = rear = -1;
		}

		int isEmpty()
		{
			if(rear = -1)
				return FALSE;
			else 
				return TRUE;
		}
		
		int isFull()
		{
			if(rear > 4)
				return FALSE;
			else 
				return TRUE;
		}

		void add(int n)
		{
			rear++;
			if(rear =  0)
				front = rear;
			a[rear] = n;
		}	

		int del()
		{
			int n = a[rear];
			rear--;
			return n;
		}	

};

int queue::FALSE = 1;
int queue::TRUE = 0;

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
}
