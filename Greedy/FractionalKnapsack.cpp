class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item I1,Item I2)
    {
        double a = (double)I1.value/(double)I1.weight;
        double b = (double)I2.value/(double)I2.weight;
        
        return a>b;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,compare);
        
        int w=0;
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(w+arr[i].weight<=W)
            {
                w += arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                w = W-w;
                ans += ((double)w/(double)(arr[i].weight) )*(double)arr[i].value;
                break;
            }
        }
        return ans;
    }
        
};