// Question Link : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// Input:
// N = 16
// A[]={0,8,4,12,2,10,6,14,1,9,5
//      13,3,11,7,15}
// Output: 6
// Explanation:Longest increasing subsequence
// 0 2 6 9 13 15, which has length 6
// Time Complexity : O(N^2)
// Space complexity : O(N)

#include<bits/stdc++.h>
using namespace std;

int longIncrSeq(int arr[],int N)
{
	// store positions of previous smaller element
	int output[N]={1};

	for(int i=1;i<N;i++)
	{
		// start traversing from first index
		// if element is less than current element
		// chance to include in subsequence
		// maximize it
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
				output[i] = max(output[i],output[j]+1);
		}
	}

	int ans = INT_MIN;
	// find maximum length subsequence formed in array
	for(int i=0;i<N;i++) ans = max(ans,output[i]);

	return ans;
}

int main()
{
	int N;cin>>N;
	int arr[N];
	for(int i=0;i<N;i++) cin>>arr[i];

	cout<<longIncrSeq(arr,N);
}




