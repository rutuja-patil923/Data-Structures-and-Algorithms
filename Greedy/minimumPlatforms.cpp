int findPlatform(int arr[], int dep[], int n)
    {
        // no need to associate starting and departure timings of trains
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        // just checking if train needs separate platform or if some previous train has left her place.
        int platforms=1,ans=1;
        int i=1,j=0;
        
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j])
            {
                platforms++;
                i++;
            }
            else
            {
                platforms--;
                j++;
            }
                
            ans = max(ans,platforms);
        }
        
        return ans;
    }