#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main()
{
	string str;
	cin>>str;

	// power of p to be multiplied
	ll p_power=1;

	// value of p which should be greater than size of character set
	ll p = 31;

	ll hash=0;

	for(int i=0;i<str.length();i++)
	{
		hash += ((str[i]-'a'+ 1)*p_power)%mod;
		p_power = (p_power*p)%mod;
	}

	cout<<str<<" -> "<<hash;
}
