int countRev (string s)
{
    int left=0,right=0;
    if(s.length()%2) return -1;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{')
            left++;
        else
        {
            if(left==0)
                right++;
            else
                left--;
        }
    }
    
    int ans = (left/2)+(right/2);
    
    if(left%2) ans++;
    if(right%2) ans++;
    
    return ans;
}