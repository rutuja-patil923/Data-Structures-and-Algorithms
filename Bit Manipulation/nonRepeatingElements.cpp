// Question Link: https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
// Difficulty Level : Hard
// e.g Input: arr[] = {2, 3, 7, 9, 11, 2, 3, 11} output: The non-repeating elements are 7 and 9
// Expected Time complexity : O(N)
// Expected Space Complexity : O(1)

// Question Understanding : in given array every array element has occurred twice except two elements. we need to find those 2.

// Naive Approch : Sort array and check adjacent position for each of array element T.C-O(NlogN) S.C-O(1)
// Better Approch : store frequency of array element if it's 1 then will get answer. T.C-O(N) S.C-O(N)
// Optimal approch : Using XOR. 
// XOR of two same elements results into 0. so if we do XOR of all array elements except those two array elements which only occurr once XOR will become 0
// final XOR will be of those two array elements.
// now find any set position XOR Observe! it's set because in one element it's unset and another one set
// now divide array into 2 diffrent parts 
// first part of array contains that bit set another part contains bit unset
// as we find XOR of those two parts will get each of those 2 distinct elements


#include<bits/stdc++.h>
using namespace std;

void nonRepeatingElements(int arr[],int n)
{
	// XOR of all array elements
	int XOR=0;
	
	for(int i=0;i<n;i++)
		XOR ^= arr[i];
	
	// set bit position in XOR
	int posSetBit=0;	
	for(; posSetBit<32 ; posSetBit++)
	{
		int check = 1 << posSetBit;
		if(check & XOR)
			break;
	}
	
	// divide array into 2 parts
	int first=0,second=0;
	
	for(int i=0;i<n;i++)
	{
		int check=1<<posSetBit;
		
		// if array element at i has bit set will go to part 1
		if(arr[i] & check)
			first ^= arr[i];
			
		// otherwise part 2
		else
			second ^= arr[i];
	}
	
	cout<<min(first,second)<<" "<<max(first,second);
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	nonRepeatingElements(arr,n);

 	return 0;
}



