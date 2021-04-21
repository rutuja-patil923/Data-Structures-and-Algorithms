    

    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='+' || S[i]=='-' || S[i]=='*' || S[i]=='/')
            {
                int second=st.top();st.pop();
                int first=st.top();st.pop();
                
                int result;
                if(S[i]=='+') result = first + second;
                if(S[i]=='-') result = first - second;
                if(S[i]=='*') result = first * second;
                if(S[i]=='/') result = first / second;
                
                st.push(result);
            }
            else
            {
                int temp=S[i]-'0';
                st.push(temp);
            }
        }
        
        return st.top();
    }