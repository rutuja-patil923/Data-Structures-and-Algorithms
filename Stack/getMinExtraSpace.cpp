#include<bits/stdc++.h>
using namespace std;

struct Stack {

	int minElement;
	stack<int> s;
	
	void push(int x)
	{
		if(s.empty())
		{
			minElement=x;
			s.push(x);
		}
		else
		{
			if(x<minElement)
			{
				s.push(2*x-minElement);
				minElement=x;
			}
			else
				s.push(x);
		}
	}
	void pop()
	{
		if(s.empty())
		{
			cout<<"Empty Stack";
			return;
		}

		int temp=s.top();

		if(temp<minElement)
		{
			cout<<minElement;
			minElement=2*minElement-temp;
		}
		else
			cout<<temp;
	}
	int top()
	{
		if(s.empty())
		{
			cout<<"Empty Stack";
			return;
		}

		int temp=s.top();

		// if it's less it means it's storing 2*currentMin-prevMin
		(temp<minElement) ? return minElement:return temp;
	}
	void getMin()
	{
		if(s.empty())
			cout<<"Stack is empty";
		else
			cout<<minElement<<" ";
	}

}

int main()
{
	Stack st;
	st.push(11);
	st.push(34);

	s.getMin();
}