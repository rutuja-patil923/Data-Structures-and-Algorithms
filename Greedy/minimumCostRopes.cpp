class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    typedef long long int ll;
    long long minCost(long long arr[], long long n) {
        
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<n;i++)
            pq.push(arr[i]);
        ll ans = 0;
        while(pq.size()>1)
        {
            ll first_row = pq.top();
            pq.pop();
            
            ll second_row=pq.top();
            pq.pop();
            
            ans += first_row+second_row;
            pq.push(first_row+second_row);
        }
            
        return ans;
    }
};