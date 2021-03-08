// Question Link: https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
// Difficulty Level : Easy
// e.g Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}  output: arr2[] is a subset of arr1[]
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(N) 

// Question Understanding : check if given array is subset of another

// Naive approch : check each element in second array is present in first array through two for loops T.C-O(N^2)
// Better approch : sorting and Binary search sort first array and for each element in second array find if that present in first array with Binary Search T.C-NlogM..considering first array size=M and second=N
// Approch 2 : sort both the arrays and merge if final array count is same as first array then condition is fullfilled otherwise not T.C-O(MlogM + NlogN) S.C-O(M+N)
// space complexity can be improved in approch 2 by just using counter to keep track without storing elements

// Optimal approch 1 : use hashing for first array element. Traverse second array check if it exists T.C-O(N) S.C-O(N)
// Optimal approch 2 : use unordered_set and if size is first array size then array2 is subset of array1 T.C-O(N) S.C-O(N)



// Optimal approch 1
#include<bits/stdc++.h>
using namespace std;

void subsetOfAnother(int arr[],int n,int brr[],int m)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]=1;
	
	for(int i=0;i<m;i++)
	{
		if(mp.find(brr[i])==mp.end())
		{
			cout<<"Not a subset";
			return;
		}
	}
	cout<<"Subset";
}

//main function
int main()
{
 	int n,m;cin>>n>>m;
 	int arr[n],brr[m];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	for(int i=0;i<m;i++) cin>>brr[i];
 	
 	subsetOfAnother(arr,n,brr,m);
 	
 	return 0;
}


