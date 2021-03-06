// Question Link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// Difficulty Level : Medium
// e.g Input: 2 1 5 6 3 k =3 output:1..[swap 5 and 3 so that all elements less tha or equal to 3 will come together]
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(1) 

// Question Understanding : We need to do minimum swaps means filling gaps is important here which need tobe minimized.
// In more simpler way if for example 1 represents element less tha or eual to k and 0 represents greater elements
// e.g 1 1 [0 0] 1 1 1 0 0 1 1 in this example last two elements can be swapped and they should fill the gap of 2 represented in square brackets.
// conclusion will be find such window of k elements where gaps are less.

// Naive approch : traverse for each subarray and find minimum gap window Time complexity: O(N^2)
// Better approch : use of sliding window technique..[refer GFG for sliding window technique]
// First count all elements which are less than or equal to k. Then make window of that count and final answer will be minimum no. of elements in each window which are greater than k.


#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int k)
{
	int countLessK=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=k)
			countLessK++;
	}
	
	int countMoreK=0;
	for(int i=0;i<countLessK;i++)
	{
		if(arr[i]>k)
			countMoreK++;
	}
	int ans=countMoreK;
	
	for(int i=1,j=countLessK;j<n;i++,j++)
	{
		// excluding previous element
		if(arr[i-1]>k)
			countMoreK--;
			
		// including next element in window
		if(arr[j]>k)
			countMoreK++;
			
		ans=min(ans,countMoreK);
	}
	return ans;
	
}

//main function
int main()
{
 	int n,k;cin>>n>>k;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<"Minimum swaps required to bring elements together that are less than or equal to k are "<<solve(arr,n,k);
 	return 0;
}


