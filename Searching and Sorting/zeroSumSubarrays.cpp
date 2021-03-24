// Quesion Link : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are 
// [0], [0], [0], [0], [0,0], and [0,0]
// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)

// Approch : sum of subarray is 0 if either array element is 0 or prefix sum has been appeared before
// e.g array = {0 0 5 5 0 0} prefix sum array = {0 0 5 10 10 10}
// subarrays having sum = 0 -> [0],[0],[0,0],[0],[0],[0,0]

//_____________________________________________________________________________________________________________

#include<bits/stdc++.h>
using namespace std;

int zeroSumSubarrays(int nums[],int N)
{
	ll prefix[n+1] ={0};
        
    // map to store no.f times sum has occurred before
    unordered_map<ll,ll> up;
    up[0] = 1;
        
    ll count = 0;
        
    for(ll i=1;i<=n;i++)
    {
        // sum till i
        prefix[i] += prefix[i-1] + arr[i-1];
            
        // if sum has occurred before then subarray exists having sum 0
        // total subarrays having sum 0 will be no. of times it has occurred
        if(up.find(prefix[i]) != up.end())
           count += up[prefix[i]];
                
        // increasing count
        up[prefix[i]] ++;
    }
        
    return count;
}
int main()
{
	int N;cin>>N;
	int nums[N];
	for(int i=0;i<N;i++) cin>>nums[i];

	cout<<zeroSumSubarrays(nums,N);
}