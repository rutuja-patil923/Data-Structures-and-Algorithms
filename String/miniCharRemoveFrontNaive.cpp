#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int start,int end,string ip)
{
	while(start<end)
	{
		if(ip[start]!=ip[end])
			return false;
	}
	return true;
}
int main()
{
	string ip;
	cin>>ip;

	for(int i=ip.length()-1;i>=0;i--)
	{
		if(isPalindrome(0,i,ip))
		{
			cout<<ip.length()-1-i;
			break;
		}
	}
}