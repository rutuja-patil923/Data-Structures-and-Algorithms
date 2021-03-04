// Question Link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// Difficulty Level : Basic
// e.g Input: 4 2 -3 1 6 output: YES [subarray {2,-3,1} has sum 0]
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(N) [for storing sums in map]

// Naive approch : check if any subarray has 0 sum by taking 2 for loops Time Complexity: O(N^2)
// Better approch : will create prefix array which will store sum of array elements until that index e.g prefix[3] will contain sum of elemnts starting from index 0 to 3.
// After creating prefix array check for two conditions one is if at some i prefix[i]=0 occurs which clearly shows that sum of subarray till index i from starting is 0
// Next condion to check is if for some j prefix[j] already present at some i which means subarray starting from i+1 till j has sum 0
// reason being prefix[j]-prefix[i] contains subarray sum starting from i to j.

#include<bits/stdc++.h>
using namespace std;

int subarray_zero_sum(int a[],int n)
{
	//prefix array 
	int prefix[n]={0};
	prefix[0]=a[0];
	for(int i=1;i<n;i++)
		prefix[i]=prefix[i-1]+a[i];
	
	//map to check if sum occured before
	unordered_map<int,int> up;
	
	for(int i=0;i<n;i++)
	{
		if(prefix[i]==0 || up.find(prefix[i])!=up.end())
			return 1;
		up[prefix[i]]=1;
	}
	
	return 0;
	
}

//main function
int main()
{
 	//taking array input
	int n;cin>>n;
 	int a[n];
 	for(int i=0;i<n;i++) cin>>a[i];
 	
 	if(subarray_zero_sum(a,n))
 		cout<<"Present";
 	else
 		cout<<"Not Present";
 		
 	return 0;
}


