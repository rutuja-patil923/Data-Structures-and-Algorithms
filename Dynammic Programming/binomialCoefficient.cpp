// Question Link : https://practice.geeksforgeeks.org/problems/ncr1019/1#
// Input: n = 3, r = 2
// Output: 3
// Explaination: 3C2 = 3
// Expected Time Complexity: O(n*r)
// Expected Auxiliary Space: O(r)

// Approch : 1          ...0c0
          // 1 1        ...1c0 1c1
          // 1 2 1      ...2c0 2c1 2c2
          // 1 3 3 1    ...3c0 3c1 3c2 3c3
// Pascal traingle : where each block represents = (previous row(j) + previous row(j-1))


#include<bits/stdc++.h>
using namespace std;

int binomialCoeffient(int n,int r)
{
	int mod = 1e9 + 7;
    if(n<r) return 0;
        
    int dp[r+1]={0};
        
    dp[0] = 1;
        
    for(int i=1;i<=n;i++)
    {
        // calculating till r is enough
        for(int j=min(i,r);j>=1;j--)
            dp[j] = (dp[j] + dp[j-1])%mod;
    }
        
    return dp[r];
}

int main()
{
	int N,int R;
	cin>>N>>R;

	cout<<binomialCoeffient(N,R);
}