static bool compare(Job j1,Job j2)
    {
        return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
            
        int deadLines[102];
        memset(deadLines,-1,sizeof(deadLines));
        
        sort(arr,arr+n,compare);
        
        int ans=0,cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>=1;j--)
            {
                if(deadLines[j]==-1)
                {
                    deadLines[j]=arr[i].id;
                    cnt++;
                    ans += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> res{cnt,ans};
        return res;
    } 

