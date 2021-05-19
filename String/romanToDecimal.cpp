int romanToDecimal(string &str) 
{
    
    map<char,int> mp;
    mp['I']=1;mp['V']=5;mp['X']=10;mp['L']=50;mp['C']=100;mp['D']=500;mp['M']=1000;
    
    int ans=0;
    for(int i=0;i<str.length();i++)
    {
        if(mp[str[i]]<mp[str[i+1]])
        {
            ans += mp[str[i+1]]-mp[str[i]];
            i++;
            continue;
        }
        ans += mp[str[i]];
    }
    
    return ans;
}