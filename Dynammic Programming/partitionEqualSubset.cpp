// Question Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explaination: 
// The two parts are {1, 5, 5} and {11}
// Expected Time Complexity: O(N*sum of elements)
// Expected Auxiliary Space: O(N*sum of elements)


// Top-down approch

#include<bits/stdc++.h>
using namespace std;

// for storage 
bool dp[1000][1000];

bool equalSumPartition(int arr[],int N,int sum)
{
	// with 0 array elements sum can't be achieved
	for(int j=0;j<=sum;j++)
		dp[0][j]=false;

	// sum 0 can be achieved by any no. of array elements
	// empty array
	for(int i=0;i<=N;i++)
		dp[i][0]=true;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
				dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[N][sum];
}


int main()
{
	int N;
	cin>>N;

	int arr[N],sum=0;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		sum += arr[i];
	}
	
	// we need to find if any subset exists with sum/2
	// so that array can be partitioned into halves
	sum /= 2;

	cout<<equalSumPartition(arr,N,sum);
}















