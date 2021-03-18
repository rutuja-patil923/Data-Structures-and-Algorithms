#include<bits/stdc++.h>
using namespace std;

int friendsPairing(int N)
{
	int dp[N+1];

	// two ways 
	// 1. element is single - no. ways will be same as previous one
	// 2. element makes pair - no can make pair with N-1 elements and remaining N-2 elements will form pair in themselves
	// Total ways = element as a single + element makes pair

	// base conditions
	// for N = 1 , {1}
	// for N = 2 , {1}{2},{1,2}
	dp[1]=1;
	dp[2]=2;

	// choice diagram
	// first term when it's been single
	// next is making pair
	// choices are N-1 
	for(int i=3;i<=N;i++)
		dp[i] = dp[i-1] + (i-1) * dp[i-2];

	return dp[N];
}

int main()
{
	int N;cin>>N;
	cout<<friendsPairing(N);
}