// Question Link: https://www.includehelp.com/icp/palindromic-array.aspx
// Difficulty Level : Medium
// e.g Input: 5 3 4 6 9 3 5 output: 2..[4+6=10,10+9=19 final array will look like 5 3 19 2 5]
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) 

// Question Understanding: find no. of operations can be made to make array palindrome.
// operation is that can add adjacent numbers and use their sum as an array element

// Approch : so in such case recursion can be useful. Like strting from first and last index and the keep on shrinking the array size and one condion will occur where we need to stop
// this kind of scenario is similar to what we do in recursion.
// 3 conditions will occur while comparing elements 
// suppose index starting index is i and ending index is j 3 condions be a[i]==a[j],a[i]>a[j],a[i]<a[j]
// in first condition where elements are same no need to change anything move ahead.
// in second condition check the possibility if by adding adjacent element of j element can be made equal to a[i]
// same goes with third condition as explained in second here checking for i.


#include<bits/stdc++.h>
using namespace std;

int minOperations(int arr[],int left,int right)
{
	//if it contains only one element
	if(left==right)
		return 0;
	if(left<right)
	{
		if(arr[left]==arr[right])
			return minOperations(arr,left+1,right-1);
		else if(arr[left]>arr[right])
		{
			arr[right-1]=arr[right]+arr[right-1];
			return minOperations(arr,left,right-1)+1;
		}
		else
		{
			arr[left+1]=arr[left]+arr[left+1];
			return minOperations(arr,left+1,right)+1;
		}
	}
	return 0;
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<"No. of minimum operations to make array Palindrome are: "<<minOperations(arr,0,n-1);
 	
 	
 	return 0;
}


