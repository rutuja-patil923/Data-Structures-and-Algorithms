// Question Link: https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
// Difficulty Level : Baisc
// Input: 
// N = 5
// Arr[] = {15, 2, 45, 12, 7}
// Output: 2
// Expected Time complexity : O(N)
// Expected Space Complexity : O(1)

// Approch : Traverse array once and find position equal to array element

#include<bits/stdc++.h>
using namespace std;

void valueEqualIndex(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == i+1)
			cout<<arr[i]<<" ";
	}
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
	
	valueEqualIndex(arr,n);
 	return 0;
}



