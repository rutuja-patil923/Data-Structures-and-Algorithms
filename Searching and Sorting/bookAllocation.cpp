    typedef long long ll;
    int findPages(int arr[], int n, int m) 
    {
        if(m>n)
            return -1;
        ll sum=0;
        for(int i=0;i<n;i++)
            sum += arr[i];
            
        //sort(arr,arr+n);
            
        ll low = arr[0],high = sum,count;
        ll ans = INT_MAX;
        //cout<<low<<" "<<high<<'\n';
        while(low<=high)
        {
            ll mid = (low+high)/2;
            
            count=1;
            //cout<<"-------------------------------------------------"<<endl;
            ll temp=0,res=INT_MIN;
            
            for(int i=0;i<n;i++)
            {
                if(temp + arr[i]<=mid)
                    temp += arr[i];
                else
                {
                    count++;
                    //cout<<mid<<" "<<count<<endl;
                    //cout<<mid<<" "<<temp<<endl;
                    res = max(res,temp);
                    temp=arr[i];
                }
            }
            res = max(res,temp);
            
            if(count>m)
                low = mid+1;
            else
            {
                ans = min(ans,res);
                high = mid-1;
            }
                
        }
        
        return ans;
    }