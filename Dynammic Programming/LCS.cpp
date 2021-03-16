// Question Link : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input Sequences
// “ABCDGH” and “AEDFHR” is “ADH” of
// length 3
// Expected Time Complexity: O(|str1|*|str2|)
// Expected Auxiliary Space: O(|str1|*|str2|)


// Top-down approch

#include<bits/stdc++.h>
using namespace std;

// for storage 
int dp[1000][1000];

int LCS(string str1,string str2)
{
	// first string length
	int n = str1.length();

	// second string length
	int m = str2.length();

	// base condition
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			// if any of string is empty ans will be 0
			if(i==0 || j==0)
				dp[i][j]=0;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// if last character matches
			if(str1[i-1] == str2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];

			// if not then we can decrease iterator of either of them
			// taking maximum
			else
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	}

	return dp[n][m];
}


int main()
{
	string str1,str2;
	cin>>str1>>str2;

	cout<<LCS(str1,str2);
}















