#include<bits/stdc++.h>
using namespace std;

#define SIZE 10

class Queue {

	int *arr;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue(int size=SIZE);
	~Queue();
	void deQueue();
	void enQueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

Queue:: Queue(int size)
{
	arr= new int[size];
	capacity=size;
	front=0;
	rear=-1;
	count=0;
}

Queue::~Queue()
{
	delete [] arr;
}

void Queue::deQueue()
{
	if(isEmpty())
	{
		cout<<"Queue is Empty";
		return;
	}
	//cout<<"Removing front element "<<arr[front];
	front=(front+1)%capacity;
	count--;
}

void Queue::enQueue(int x)
{
	if(isFull())
	{
		cout<<"Queue is full";
		return;
	}
	rear=(rear+1)%capacity;
	arr[rear]=x;
	count++;
}

int Queue::peek()
{

	if(isEmpty())
	{
		cout<<"Queue is Empty";
		return -1;
	}
	return arr[front];
}

int Queue::size()
{
	return count;
}

bool Queue::isEmpty()
{
	return size()==0;
}

bool Queue::isFull()
{
	return size()==capacity;
}


int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);

	q.deQueue();

	while(!q.isEmpty())
	{
		cout<<q.peek()<<" ";
		q.deQueue();
	}

}
