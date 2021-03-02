// Question Link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// Difficulty Level : Basic 
// e.g Input: 1 2 3 4 5 output: 5 4 3 2 1
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) [Only use of temporary variable for swapping]
// Another Approch: swapping can be done with recursion as well 

#include<bits/stdc++.h>
using namespace std;

void reverse_Array(int arr[],int n)
{
	//simply swap the array elements till middle
	
	int left=0,right=n-1;
	while(left<right)
	{
		swap(arr[left],arr[right]);
		left++;
		right--;
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
 	
 	reverse_Array(arr,n);
 	print_Array(arr,n);
	 
	return 0;
}

