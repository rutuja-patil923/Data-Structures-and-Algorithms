#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;


	map<char,pair<int,int>> mp;

	for(int i=0;i<=17;i++)
	{
		char ch = (char)(i+'A');

		mp[ch] = {(i/3)+2,i%3 +1};
	}

	mp['S'] = {7,4};
	mp['T'] = {8,1};
	mp['U'] = {8,2};
	mp['V'] = {8,3};
	mp['W'] = {9,1};
	mp['X'] = {9,2};
	mp['Y'] = {9,3};
	mp['Z'] = {9,4};


	string ans="";
	for(int i=0;i<str.length();i++)
	{
		int cnt = mp[str[i]].second;

		while(cnt--)
			ans += to_string(mp[str[i]].first);
	}

	cout<<ans;
}
