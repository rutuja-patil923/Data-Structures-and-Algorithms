public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        
        int mini=0,maxi=0,sum=0;
        for(int i=0;i<N;i++) sum+=candies[i];
        if(K==0)
        {
            vector<int> ans={sum,sum};
            return ans;
        }
        
        sort(candies,candies+N);
        
        int check = (N/(K+1));
        if(N%(K+1)) check++;
        for(int i=0;i<check;i++)
        {
            mini += candies[i];
            maxi += candies[N-i-1];
        }
        
        vector<int> ans={mini,maxi};
        return ans;
    