#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(int top,stack<int>&s)
{
	if(s.empty())
	{
		s.push(top);
		return;
	}
	int temp=s.top();
	s.pop();

	insertAtBottom(top,s);

	s.push(temp);
}
void reverstack(stack<int>& s)
{
	if(s.empty())
		return;

	int top=s.top();
	s.pop();

	reverstack(s);

	insertAtBottom(top,s);
}

int main()
{
	stack<int> st;
	st.push(3);
	st.push(2);
	st.push(1);


	reverstack(st);

	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}


}
