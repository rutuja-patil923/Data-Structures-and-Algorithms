#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&s,int top)
{
	if(s.empty())
	{
		s.push(top);
		return;
	}
	int temp=s.top();
	if(top<temp)
	{
		s.pop();
		insertAtBottom(s,top);
		s.push(temp);
	}
	else
		s.push(top);
}
void sortStack(stack<int> &s)
{
	if(s.empty())
		return;

	int top=s.top();
	s.pop();

	sortStack(s);

	insertAtBottom(s,top);
}

int main()
{
	stack<int> s;
	s.push(4);
	s.push(2);
	s.push(1);

	sortStack(s);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
