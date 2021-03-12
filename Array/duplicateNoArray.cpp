// Question Link: https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty Level : Medium
// Input: nums = [1,3,4,2,2]
// Output: 2
// Expected Time complexity : O(N)
// Expected Space Complexity : O(1)

// Question Understanding : Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.

// Naive Approch : Sort array and find if adjacent numbers are same T.C- O(NlogN)
// Better Approch : Use of Hashing. Store frequency of elements and find if any number is present in frequency array before. T.C-O(N) S.C-O(N)
// Optimal Approch : Space complexity in better approch should be reduced to O(1)
// For that Floyd Cycle detection Algorithm used in linked List can be useful
// Take two pointers slow and fast. Slow will move one steps at a time and fast will take two steps at a time.
// At some point they'll meet in loop..[Imagine loop in array because atleast one number is duplicate]
// after meeting at some point take fast pointer to first and traverse both pointers one step at a time until they meet

#include<bits/stdc++.h>
using namespace std;

void duplicateNoArray(int arr[],int n)
{
	// initilizing slow and fast pointer
	int fast=arr[0];
	int slow=arr[0];
	
	// can't directly start while loop because both slow and fast pointer are same first hence do-while loop
	// This will work because suppose until duplicate no. distance is m and after until collision point it's k
	// slow point will traverse = m + k + x*n...[where n is length of loop]
	// fast point will traverse = m + k + y*n
	// fast = 2 * slow
	// m + k + y*n = 2 *  (m + k + x*n)
	// n * (y-2*x) = m + k
	do
	{
		fast = arr[arr[fast]];
		slow = arr[slow];
	} while(slow != fast);
	
	
	// now after fast being placed at start if it traverse m distance slow will traverse same
	// but since n is multiple of (m+k) they will meet at duplicate number only
	fast = arr[0];
	
	while(slow != fast)
	{
		fast = arr[fast];
		slow = arr[slow];
	}
	
	cout<<"Duplicate no. is "<<slow;
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	duplicateNoArray(arr,n);

 	return 0;
}



