    void solve(int index,int N,string &ans,string ip)
    {
        if(index==N)
            return;
        if(ip[index]!=ip[index-1])
            ans += ip[index];
        solve(index+1,N,ans,ip);
    }
    string removeConsecutiveCharacter(string S)
    {
        string ans="";
        ans+=S[0];
        solve(1,S.length(),ans,S);
        return ans;
    }