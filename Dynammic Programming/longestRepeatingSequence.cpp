// Question Link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Input: str = "axxxy"
// Output: 2
// Explanation: The longest repeating subsequenece
// is "xx"
// Time Complexity : O(N^2)
// Space Complexity : O(N^2)

// Approch : in LCS we have two strings in input but now we have only one
// To find longest repeating subsequence will use same string as second input condition will be 
// characters should not match at same index
// otherwise both strings will match
// input1 = XXY ,hence input2 = XXY but X at first index in input1 will match to 2nd index of X in input2 

#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int longRepSubseq(string input1)
{
	// take second input same string
	string input2 = input1;

	int N = input1.length();

	// base condition
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			// if any of string is empty
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			// if character matches but not on same position
			if(input1[i-1] == input2[j-1] && i!=j)
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				// same as LCS
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	return dp[N][N];
}

int main()
{
	string input1;cin>>input1;

	cout<<longRepSubseq(input1);
}








