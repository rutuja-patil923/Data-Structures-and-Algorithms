// Question Link : https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

#include<bits/stdc++.h>
using namespace std;

int editDistance(string str1,string str2)
{
	int N = str1.length();
	int M = str2.length();

	int dp[N+1][M+1];

	// base condition
	// if any of the string is empty then we need to add that many no. characters
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(i==0)
				dp[i][j] = j;
			if(j==0)
				dp[i][j] = i;
		}
	}

	// choice diagram
	// suppose take two strings , str1 = "this" str2 = "there"
	// think for recursive solution
	// here last character of both strings is not matching
	// condition 1 : replace... s with e .. N-1,M-1...thie there
	// condition 2 : insert e...N,M-1 thise there
	// condition 3 : delete s...N-1,M thi there
	// take minimum from all three conditions

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			// last character matches just move towards left for both strings
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				// 3 conditions for replacement,deletion,insertion respectively
				// +1 for operation
				dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
		}
	}

	return dp[N][M];

}

int main()
{
	string str1,str2;
	cin>>str1>>str2;

	cout<<editDistance(str1,str2);
}