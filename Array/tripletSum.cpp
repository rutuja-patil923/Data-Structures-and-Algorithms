// Question Link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
// Difficulty Level : Medium
// e.g Input: array = {12, 3, 4, 1, 6, 9}, sum = 24 output: 12, 3, 9
// Expected Time complexity : O(N^2) [Traversing array once]
// Expected Space Complexity : O(1) [Only use of temporary variable for swapping]

// Question Understanding : In this question we need to find triplet with the given sum

// Naive approch : with 2 nested loops we can check if array contain any triplet with given sum T.C-O(N^3)
// Better Approch : we can do hashing so will find sum in 2 nested and if 3rd element exists in array then triplet is present T.C-O(N^2) S.C-(O(N)
// Optimal approch : space complexity in the better approch can be improved by using sorting.
// First sort array and then find sum-arr[i] in the remaining array with two pointer technique 

#include<bits/stdc++.h>
using namespace std;

void tripletSum(int arr[],int n,int sum)
{
	// sort array first
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
	{
		// check if checkSum exists in remaining array
		int checkSum=sum-arr[i];
		
		int left=0,right=n-1;
		
		// two pointer technique for finding checkSum
		while(left<=right)
		{
			if(arr[left]+arr[right]<checkSum)
				left++;
			else if(arr[left]+arr[right]>checkSum)
				right--;
			else
			{
				cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right];
				return;
			}
		}
	}
}

//main function
int main()
{
 	int n,sum;cin>>n>>sum;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	tripletSum(arr,n,sum);
}


