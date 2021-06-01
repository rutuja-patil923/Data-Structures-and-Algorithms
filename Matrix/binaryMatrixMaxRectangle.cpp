    vector<int> leftSmaller(int arr[],int m)
    {
        vector<int> v;
        stack <pair<int,int>> st;
        
        for(int i=0;i<m;i++)
        {
            if(st.empty())
                v.push_back(-1);
            else
            {
                while(!st.empty() && st.top().second>=arr[i])
                    st.pop();
                if(st.empty())
                    v.push_back(-1);
                else
                    v.push_back(st.top().first);
            }
            st.push({i,arr[i]});
        }
        return v;
    }
    vector<int> rightSmaller(int arr[],int m)
    {
        vector<int> v;
        stack<pair<int,int>> st;
        
        for(int i=m-1;i>=0;i--)
        {
            if(st.empty())
                v.push_back(m);
            else
            {
                while(!st.empty() && st.top().second>=arr[i])
                    st.pop();
                if(st.empty())
                    v.push_back(m);
                else
                    v.push_back(st.top().first);
            }
            st.push({i,arr[i]});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int maxAreaHistogram(int arr[],int m)
    {
        vector<int> left = leftSmaller(arr,m);
        vector<int> right = rightSmaller(arr,m);
        
        int ans=INT_MIN;
        
        for(int i=0;i<m;i++)
        {
            int area = (right[i]-left[i]-1)*arr[i];
            
            ans = max(area,ans);
        }
        
        return ans;
        
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                    M[i][j] += M[i-1][j];
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int result = maxAreaHistogram(M[i],m);
            
            ans = max(result,ans);
        }
        
        return ans;
    }