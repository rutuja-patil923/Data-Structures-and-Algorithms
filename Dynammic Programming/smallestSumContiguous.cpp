// Question Link : https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/
// Input : arr[] = {3, -4, 2, -3, -1, 7, -5}
// Output : -6
// Subarray is {-4, 2, -3, -1} = -6
// Expected Complexity : O(N)

// Naive Approch : using two loops traverse each subarray and find minimum sum O(N*N)
// Efficient Approch : same as kadane's algorithm

#include<bits/stdc++.h>
using namespace std;

int smallestSum(int N,int nums[])
{
	int local_sum = 0;
	int global_sum = INT_MAX;

	for(int i=0;i<N;i++)
	{
		// here checking if either keeping element as it is or by adding sum will become minimum
		local_sum = min(local_sum+nums[i],nums[i]);

		// updating answer till now
		if(local_sum < global_sum)
			global_sum = local_sum;
	}
	return global_sum;
}

int main()
{
	int N;cin>>N;
	int nums[N];
	for(int i=0;i<N;i++) cin>>nums[i];

	cout<<smallestSum(N,nums);
}
