#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1+1][n2+1][n3+1];
    
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            for(int k=0;k<=n3;k++)
            {
                if(i==0 || j==0 || k==0)
                    dp[i][j][k]=0;
            }
        }
    }
    
    int ans = 0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            for(int k=1;k<=n3;k++)
            {
                if(A[i-1] == B[j-1] && A[i-1] == C[k-1])
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                    
                    ans = max(ans,dp[i][j][k]);
                }
                else
                {
                    // combinations
                    int maxi1 = max(dp[i-1][j][k],dp[i-1][j-1][k]);
                    int maxi2 = max(dp[i][j-1][k],dp[i][j][k-1]);
                    int maxi3 = max(dp[i-1][j][k-1],dp[i][j-1][k-1]);
                    
                    dp[i][j][k] = max(max(maxi1,maxi2),maxi3);
                }
                    
            }
        }
    }
    
    return ans;
}

int main()
{
    string str1,str2,str3;
    cin>>str1>>str2>>str3;

    cout<<LCSof3(str1,str2,str3,str1.length(),str2.length(),str3.length());
}