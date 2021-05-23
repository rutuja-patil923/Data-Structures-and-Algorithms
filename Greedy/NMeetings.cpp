
class Solution
{
    public:
    struct meet
    {
        int st;
        int en;
    };
    static bool compare(struct meet m1,struct meet m2)
    {
        return m1.en < m2.en ;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meet arr[n];
        
        for(int i=0;i<n;i++)
        {
            arr[i].st = start[i];
            arr[i].en = end[i];
        }
        
        sort(arr,arr+n,compare);
        
        int ans=1;
        
        int limit=arr[0].en;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i].st>limit)
            {
                ans++;
                limit = arr[i].en;
            }
        }
        
        return ans;
    }
};