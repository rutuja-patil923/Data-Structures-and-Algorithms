long long int maximizeSum(long long int a[], int n, int k)
    {
        
        priority_queue <long long int,vector<long long int>,greater<long long int>> pq;
        
        for(int i=0;i<n;i++)
            pq.push(a[i]);
            
        while(k--)
        {
            long long int tmp = pq.top();
            pq.pop();
            
            tmp = (-1)*tmp;
            
            pq.push(tmp);
        }
        
        long long int sum =0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
        
    }