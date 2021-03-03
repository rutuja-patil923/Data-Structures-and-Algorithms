// Question Link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
// Difficulty Level : Basic
// e.g Input: 1 2 3 4 5 output: 5 1 2 3 4
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) [Only use of temporary variable]

// Naive approch with space complexity : O(N) take temprary array itself store elemnts from index 1 and and at last first element. Time complexity will remain unchanged.



#include<bits/stdc++.h>
using namespace std;

void cyclically_rotate_by_one(int arr[],int n)
{
	//temprary storing first element
	int temp=arr[n-1];
	
	//traversing backwards
	for(int i=n-1;i>0;i--)
		arr[i]=arr[i-1];
		
	//finally moving first element to last
	arr[0]=temp;
}

void print_Array(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//main function
int main()
{
 	//taking input for array
	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	print_Array(arr,n);
	cyclically_rotate_by_one(arr,n);
 	print_Array(arr,n);
 	
 	return 0;
}


