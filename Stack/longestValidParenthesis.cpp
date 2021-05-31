#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int N = str.length();
	vector<int> longest(N,0);
	stack<int> st;
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(str[i]=='(')
			st.push(i);
		else
		{
			if(st.empty()) continue;

			else
			{
				int cnt = i - st.top() + 1;
				longest[i] = cnt;
				if(i-cnt > 0)
					longest[i] += longest[i-cnt];
				ans = max(ans,longest[i]);
				st.pop();
			}
		}
	}

	return ans;
}