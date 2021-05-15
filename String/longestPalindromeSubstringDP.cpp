string longestPalin (string S)
{
    // your code here
    int N = S.length();
    int len = INT_MIN,x,y;
    
    bool dp[N][N];
    memset(dp,false,sizeof(dp));
    
    for(int i=N-1;i>=0;i--)
    {
        for(int j=i;j<=N-1;j++)
        {
            if(i==j)
                dp[i][j]=true;
            else if(S[i]==S[j])
            {
                if(j-i==1)
                    dp[i][j]=true;
                else
                    dp[i][j]=dp[i+1][j-1];
            }
            
            if(j-i>=len && dp[i][j])
            {
                len = j-i;
                x=i;
                y=j;
            }
        }
    }
    // if(len==1)
    // {
    //     string res="";
    //     res += S[0];
    //     return res;
    // }
    return S.substr(x,y-x+1);
}