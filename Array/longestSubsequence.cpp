// Question Link: https://www.geeksforgeeks.org/longest-consecutive-subsequence/
// Difficulty Level : Medium
// e.g Input: arr[] = {1, 9, 3, 10, 4, 20, 2} output: 4 ..[1,2,3,4]
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(N) 

// Question Understanding : we need to find subsequence which longest in array and contains conscecutive elements.
// e.g in given example above 1,,2,3,4 is subsequence which may not be consecutive in array but after sorting those elements they'll become consecutive integers

// Naive approch : sort array and find longest consecutive subarray by checking adjacent elements T.C-O(NlogN) S.C-O(1)
// Optimal Approch : Use hashing! store elements in map first and check if array element is starting point of subsequence. traverse and keep track of longest consecutive integers 
// T.C- O(N) S.C-O(N)

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]=1;
		
	int ans=INT_MIN;
	for(int i=0;i<n;i++)
	{
		//  it means this array element is start of consequence
		if(mp.find(arr[i]-1)==mp.end())
		{
			int x=arr[i];
			int len=0;
			
			while(mp[x])
			{
				x++;
				len++;
			}
			
			ans=max(len,ans);
		}
	}
	return ans;
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<"Length of longest consequence of consecutive intergers is "<<longestSubsequence(arr,n);
 	
 	return 0;
}


