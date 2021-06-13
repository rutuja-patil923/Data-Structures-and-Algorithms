	int minSwaps(vector<int>&nums)
	{
	    vector<int> arr(nums.begin(),nums.end());
	    sort(arr.begin(),arr.end());
	    
	    map<int,int> mp;
	    for(int i=0;i<arr.size();i++)
	        mp[arr[i]]=i;
	        
	    vector<int> vis(nums.size(),0);
	    int ans=0;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        int cycle_size=0;
	        int j = i;
	        
	        while(vis[j]!=1)
	        {
	            vis[j]=1;
	            j = mp[nums[j]];
	            cycle_size++;
	        }
	        
	        if(cycle_size > 1)
	            ans += cycle_size-1;
	    }
	    
	    return ans;
	}