// Question Link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
// Difficulty Level : Easy
// e.g Input: -1 2 3 -4 -5 output: -1 -4 -5 2 3
// Note: order of elements may vary.
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) [Only use of temporary variable]


// Naive approch : sort array-O(NlogN)
// Better approch : Store negative numbers in one array and positive in another and then merge- Extra Space for array
// Optimal Approch 1 : Two pointer or same as Dutch National flag 
// Optimal Approch 2 : Partition process of quicksort...refer GFG

#include<bits/stdc++.h>
using namespace std;

void move_negative_and_positive(int arr[],int n)
{
	int low=0,high=n-1;
	
	while(low<=high)
	{
		if(arr[low]>0)
		{
			swap(arr[low],arr[high]);
			high--;
		}
		else
			low++;
	}
}

void print_Array(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

//main function
int main()
{
 	//Taking input of array and no. of array elements
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	move_negative_and_positive(arr,n);
	print_Array(arr,n);
 	return 0;
}


