// Question Link : https://practice.geeksforgeeks.org/problems/coin-change2448/1
// Input:
// n = 4 , m = 3
// S[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}
// Expected Time Complexity: O(m*n).
// Expected Auxiliary Space: O(n*m)


// Top-down approch

#include<bits/stdc++.h>
using namespace std;

// for storage 
int dp[1000][1000];

int coinChange(int coins[],int sum,int N)
{
	// base consitions

	// if we have 0 coins then it's not possible to have required amount
	for(int j=0;j<=sum;j++)
		dp[0][j] = 0;

	// if required amount is 0
	// then it's possible with empty array with any no. of array elements
	for(int i=0;i<=N;i++)
		dp[i][0] = 1;

	// choice 
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(coins[i-1] <= j)
				// inclusion and exclusion
				// unbounded knapsack
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[N][sum];

}


int main()
{
	int sum,N;
	cin>>sum>>N;

	int coins[N];
	for(int i=0;i<N;i++)
		cin>>coins[i];
	
	cout<<coinChange(coins,sum,N);
}








