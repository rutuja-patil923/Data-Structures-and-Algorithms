// Question Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Expected Time Complexity: O(N*W)
// Expected Auxiliary Space: O(N*W)


// Top-down approch

#include<bits/stdc++.h>
using namespace std;

// for storage 
int dp[1000][1000];

int maxProfit(int values[],int weights[],int N,int W)
{
	// base condition
	// if no. of elements are 0 or total weight is 0 
	// profit will become 0 only
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
		}
	}


	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=W;j++)
		{
			// we can include weight only if it is less than total weight
			if(weights[i-1] <= j)
				// inclusion and exclusion case
				dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[N][W];
}


int main()
{
	int N,W;
	cin>>N>>W;

	int values[N],weights[N];
	for(int i=0;i<N;i++)
		cin>>values[i];
	for(int i=0;i<N;i++)
		cin>>weights[i];

	cout<<maxProfit(values,weights,N,W);
}















