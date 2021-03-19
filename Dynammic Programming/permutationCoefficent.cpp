// Question Link : https://www.geeksforgeeks.org/permutation-coefficient/
// Time Complexity : O(N*K)
// Space Complexity : O(N*K)


// Remaining approches:
// O(N) space : run a loop to find factorials P(N,K) = N!/(N-K)!
// O(1) space : temprary varible to store multiplication till n-k

#include<bits/stdc++.h>
using namespace std;

int permutationCoefficient(int N,int K)
{
	int dp[N+1][K+1];

	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			// base condition
			// if k=0 Np0 is always 1
			if(j==0)
				dp[i][j] = 1;
			else
				// recurrence relation : P(N,K) = P(N-1,K) + K*P(N-1,K-1)
				dp[i][j] = dp[i-1][j] + j*dp[i-1][j-1];

			// if j>i
			dp[i][j+1] = 0;
		}
	}

	return dp[N][K];
}

int main()
{
	int N,K;
	cin>>N>>K;

	cout<<permutationCoefficient(N,K);
}