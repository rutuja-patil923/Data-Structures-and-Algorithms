// Question Link : https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
// Input : GEEKSFORGEEKS
// Output : 5 ...[EEKEE,EESEE,..]
// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

// Approch : Problem is similar with LCS but in LCS we need two strings for input but we have only one
// Main property regarding palindrome is the string is palindrome when it's reverse matches with it
// so to check longest palindromic subsequence tale second string as reverse of first string itself

#include<bits/stdc++.h>
using namespace std;

int longPalindromicSeq(string str1)
{
	int N = str1.length();
	int dp[N+1][N+1];

	// second input
	string str2 = str1;
	reverse(str2.begin(),str2.end());

	// now same as LCS
	// base condition
	// if any of string is empty
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}

	// choice diagram
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[N][N];
}

int main()
{
	string str;
	cin>>str;

	cout<<longPalindromicSeq(str);
} 