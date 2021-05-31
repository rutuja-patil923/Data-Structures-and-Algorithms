#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    vector<int> leftSmaller(long long arr[],int n)
    {
        vector<int> v;
        stack<pair<int,long long>> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                v.push_back(-1);
                
            else
            {
                while(!st.empty() && st.top().second >= arr[i])
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
    vector<int> rightSmaller(long long arr[],int n)
    {
        vector<int> v;
        stack<pair<int,long long>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
                v.push_back(n);
            else
            {
                while(!st.empty() && st.top().second>=arr[i])
                    st.pop();
                
                if(st.empty())
                    v.push_back(n);
                else
                    v.push_back(st.top().first);
            }
            st.push({i,arr[i]});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> left = leftSmaller(arr,n);
        vector<int> right = rightSmaller(arr,n);
        
        long long ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            long long area = ((long long)(right[i]-left[i]-1) * arr[i]);
            
            ans = max(area,ans);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}