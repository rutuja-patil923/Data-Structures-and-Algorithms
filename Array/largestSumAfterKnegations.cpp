// question link : https://binarysearch.com/problems/Largest-Sum-After-K-Negations

int solve(vector<int>& nums, int k) {
    
    sort(nums.begin(),nums.end());
    int i;
    int N = nums.size();
    int sum=0;
    for(i=0;i<N;i++)
    {
        if(nums[i]>=0 || k<=0) break;

        nums[i] *=-1;

        k--;

        sum += nums[i];
    }

    if( k%2 )
    {
        if(i==N)
            sum -= 2*nums[i-1];
        else if(i==0)
            sum -= 2*nums[i];
        else
            sum -= 2* min(nums[i-1],nums[i]);
    }

    for(;i<N;i++) sum+= nums[i];

    return sum;
}