long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
            
        sort(a.begin(),a.end());
        long long diff=INT_MAX;
        
        for(long long i=0;i+m-1<n;i++)
        {
            diff = min(diff,a[i+m-1]-a[i]);
        }
        
        return diff;
    }