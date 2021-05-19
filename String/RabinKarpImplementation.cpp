#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll dp[100001];
ll inv[100001];
ll power(ll a,ll m)
{
	ll result=1;
	while(m)
	{
		if(m & 1)
			result = (result*a)%mod;
		m=m>>1;
		a = (a * a)%mod
	}

	return result;
}
void init(string text)
{
	ll p=31;
	ll p_power=1;

	// will store modulo inverse at each index
	// Fermat's Little Therom for calculating inverse modulo
	// a ^ (m-2) 
	inv[0]=1;

	// will store hash value starting from index 0
	// e.g dp[0] = hash(string(0,0))
	//     dp[1] = hash(string(0,1))
	// for each character we're starting from 1 to 26
	dp[0]= text[0]-'a'+1;

	for(int i=1;i<text.length();i++)
	{
		p_power = (p*p_power)%mod;
		inv[i] = power(p_power,mod-2);

		dp[i] = (dp[i-1] +(text[i]-'a'+1)*p_power)%mod; 
	}
}
ll gethash(string pattern)
{
	ll p=31;
	ll p_power=1;
	ll ans=0;

	for(int i=0;i<pattern.length();i++)
	{
		ans += ((pattern[i]-'a'+1)*p_power)%mod;
		p_power = (p_power*p)%mod;
	}

	return ans;
}
ll substringhash(int L,int R)
{
	ll result = dp[R];

	// if L =0 means substring starting from 0 which we already storing in dp array
	if(L>0) 
		result = (result-dp[L-1]+mod)%mod;

	// modulo operation can't be applied on divison hence taking inverse modulo
	result = (result*inv[L])%mod;
	return result;

}
int main()
{
	string text,pattern;
	cin>>text>>pattern;

	// preprocessing for main string
	init(text);

	// calculate hash for pattern first
	ll hashSub=gethash(pattern);

	// sliding window of length pattern
	for(int L=0,R=pattern.length()-1;R<text.length();L++,R++)
	{
		if(hashSub == substringhash(L,R))
			cout<<"found";
	}
}







