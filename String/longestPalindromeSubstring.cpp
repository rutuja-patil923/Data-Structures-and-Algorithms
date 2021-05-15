string longestPalin (string S)
{
    int ans = 1,left,right,cnt;
    string res="";
    //if(S.length()==0) return res;
    int L,R;
    
    for(int i=0;i<S.length();i++)
    {
        // considering odd length palindrome
        left = i-1 ; right = i+1; cnt=1;
        
        while(left>=0 && right <S.length() && S[left]==S[right])
        {
            cnt+=2;
            left--;
            right++;
        }
        
        if(cnt>ans)
        {
            L = left+1;
            R = right-1;
            ans = cnt;
        }
        // considering even length
        left = i ; right = i+1;
        cnt=0;
        
        while(left>=0 && right <S.length() && S[left]==S[right])
        {
            cnt+=2;
            left--;
            right++;
        }
        
        if(cnt>ans)
        {
            L = left+1;
            R = right-1;
            ans = cnt;
        }
    }
    if(ans==1) 
    {
        res += S[0];
        return res;
    }
    for(int i=L;i<=R;i++)
        res+=S[i];
    return res;
}