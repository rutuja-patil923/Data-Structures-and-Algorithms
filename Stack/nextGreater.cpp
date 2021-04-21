vector<long long> nextLargerElement(vector<long long> arr, int n)
{
        
        unordered_map<long long,long long> up;
        vector<long long> ans;
        stack<long long> st;
        
        st.push(arr[0]);
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && st.top()<arr[i])
            {
                up[st.top()]=arr[i];
                st.pop();
            }
            st.push(arr[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(up.find(arr[i])!=up.end())
                ans.push_back(up[arr[i]]);
            else
                ans.push_back(-1);
        }
        
        return ans;
}