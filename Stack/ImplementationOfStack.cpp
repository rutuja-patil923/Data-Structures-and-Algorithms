#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {

	int top;

public:
	int arr[MAX];

	//constructor
	Stack()
	{
		top=-1;
	}

	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if(top>=MAX-1)
	{
		cout<<"Stack Overflow";
		return false;
	}
	arr[++top]=x;
	//cout<<"Push into Stack "<<x;
	return true;
}

int Stack::pop()
{
	if(top<0)
	{
		cout<<"Empty Stack";
		return -1;
	}
	int store=arr[top];
	top--;
	return store;
}

int Stack::peek()
{
	if(top<0)
	{
		cout<<"Empty Stack";
		return -1;
	}
	return arr[top];
}

bool Stack::isEmpty()
{
	return top==-1;
}


int main()
{
	Stack st;

	st.push(10);
	st.push(11);
	st.push(12);

	while(!st.isEmpty())
	{
		cout<<st.peek()<<" ";
		st.pop();
	}

	return 0;
}
