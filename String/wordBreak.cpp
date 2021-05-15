int wordBreak(string A, vector<string> &B) {
    
    string op="";
    
    map<string,int> up;
    for(string str:B) up[str]=1;
    
    for(char ch:A)
    {
        op += ch;
        if(up.find(op)!=up.end())
            op="";
    }
    
    if(op=="")
        return 1;
    return 0;
    
}