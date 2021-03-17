// Question Link : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4
// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

// Approch : substring is different from subsequence
// in substring only consecutive characters can be considered 

#include<bits/stdc++.h>
using namespace std;

int longCommonSubstring(string str1,string str2)
{
	int N = str1.length();
	int M = str2.length();
	int dp[N+1][M+1];

	// now same as LCS
	// base condition
	// if any of string is empty
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}
	
	int ans = INT_MIN;
	// choice diagram
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(dp[i][j],ans);
			}
			else
				// if chain has ended
				// if some diffrent character occurs
				// substring count will start from 0
				dp[i][j] = 0;
		}
	}
	return ans;
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;

	cout<<longCommonSubstring(str1,str2);
} 
