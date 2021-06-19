// questin link : https://binarysearch.com/problems/Shortest-Sublist-to-Sort

int solve(vector<int>& nums) {
    
    int left,right;
    left=right=-1;
    int lmax = INT_MIN;
    int rmin = INT_MAX;

    int N = nums.size();
    for(int i=0;i<N;i++)
    {
        if(nums[i]>=lmax)
            lmax=nums[i];
        else
            right=i;

        if(nums[N-i-1]<=rmin)
            rmin=nums[N-i-1];
        else
            left = N-i-1;
    }

    if(left==-1) return 0;
    

    return right-left+1;
}