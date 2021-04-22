#include<bits/stdc++.h>
using namespace std;

class Stack {

	deque <int> st;

public:

	void push(int x)
	{
		st.push_front(x);
	}

	int pop()
	{
		int store=st.front();
		st.pop_front();
		return store;
	}
}

class Queue {

	deque <int> q;

	void enqueue(int x)
	{
		q.push_back(x);
	}

	int Deque()
	{
		int store=q.front();
		q.pop_front();
		return store;
	}
}