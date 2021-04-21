class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool ispar(string x)
    {
        stack<char> st;
        
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='(' || x[i]=='{' || x[i]=='[')
                st.push(x[i]);
                
            else
            {
                char ch=x[i];
                if(!st.empty())
                {
                    if(ch=='}' && st.top()=='{')
                        st.pop();
                    else if(ch==')' && st.top()=='(')
                        st.pop();
                    else if(ch==']' && st.top()=='[')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }

};