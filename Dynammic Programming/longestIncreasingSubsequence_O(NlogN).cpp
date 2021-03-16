// Question Link : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// Input:
// N = 16
// A[]={0,8,4,12,2,10,6,14,1,9,5
//      13,3,11,7,15}
// Output: 6
// Explanation:Longest increasing subsequence
// 0 2 6 9 13 15, which has length 6
// Time Complexity : O(NlogN)
// Space complexity : O(N)

// This approch is different from previous one
// basically we're storing elements in vector in increasing order
// if element is greter than last element of output then directly add into vector
// otherwise plce that element in place of it's next immmediate greater element

#include<bits/stdc++.h>
using namespace std;

int longIncrSeq(int arr[],int N)
{
	// resultant longest increasing subsequence
	vector<int> output;
	output.push_back(arr[0]);

	// iterator to keep track of output array
	int k=0;

	for(int i=1;i<N;i++)
	{
		if(arr[i] > output[k])
		{
			output.push_back(arr[i]);
			k++;
		}
		
		// find next immmediate element
		// as elements are leready sorted binary search can be applied
		else
		{
			// why ?
			// as we're finding longest increasing subsequence better to have smaller elements so that more and more elements can be added
			// e.g output[] = {2,5} and current element is 3
			// try adding 3 in subsequence rather than 5
			// so that if next element is 4 longest subsequence can be obtained
			int index = lower_bound(output.begin(),output.end(),arr[i])-output.begin();
			output[index] = arr[i];
		}
	}

	// size of output array will give lonegst increasing subsequence

	return output.size();
}

int main()
{
	int N;cin>>N;
	int arr[N];
	for(int i=0;i<N;i++) cin>>arr[i];

	cout<<longIncrSeq(arr,N);
}




