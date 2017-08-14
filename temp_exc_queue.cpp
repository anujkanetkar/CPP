#include <iostream>

using namespace std;

class Myex
{
	public:
		string str;
		Myex(string s)
		{
			str = s;
		}
};

template <class T>
class Queue
{
	private:
		int front, rear, n;
		T *a;
	public:
		Queue(int nn)
		{
			n = nn;
			front = rear = -1;
			a = new T[n];
		}
		
		void add(int);
		int del();
};

void Queue :: add(int x)
{
	rear++;
	a[rear] = x;
	front == -1 ? (front = 0) : (cout << ""); 
}

int Queue :: del()
{
	int x;
	x = a[front];
	front == rear ? (front = rear = -1) : (front++);	
	return x;
}

int main()
{
	int n;
	cout << "Enter size of array: " << endl;
	cin >> num;
	Queue <int> q1(num);
	Queue <float> q2(num);
	try
	{
		q1.add(10);
		q1.add(20);
		q1.add(30);
		q1.add(40);
		q1.add(50);
		q1.add(60);	
		q1.del();
		q1.del();
		q1.del();
		q1.del();
		q1.del();
		q1.del();
		q1.del();
	}
	catch(Myex e)
	{
		cout << e.str << endl;
	}

}
