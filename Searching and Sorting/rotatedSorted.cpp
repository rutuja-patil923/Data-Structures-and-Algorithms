// Question Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int> &nums)
    {
        // if array is rotated from first element
        if(nums.size()>1 && nums[0]>nums[1]) return 0;
        
        int low = 0;
        int high = nums.size()-1;
        
        // if only two elements present and they're in increasing order
        if(low == high-1) return 1;
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(mid < high && nums[mid] > nums[mid+1]) return mid;
            if(mid > low && nums[mid] < nums[mid-1]) return mid-1;
            
            if(nums[low]<=nums[mid]) low = mid+1;
            else high = mid -1;
            
        }
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target,int low,int high)
    {
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        // first find position of pivot where array has been rotated
        int Pivot = pivot(nums);
        
        // if pivot is not present
        // it means array is in increasing order
        // binary search on whole array
        if(Pivot==-1)
            return binarySearch(nums,target,0,nums.size()-1);
        else
        {
            // then two passes
            int ans = binarySearch(nums,target,0,Pivot);
            if(ans==-1)
                ans = binarySearch(nums,target,Pivot+1,nums.size()-1);
            return ans;
        }
        
    }
int main()
{
	int N,key;cin>>N>>key;
	vector<int> nums;
	for(int i=0;i<N;i++)
	{
		int x;cin>>x;
		nums.push_back(x);
	}

	cout<<search(nums,key);
}