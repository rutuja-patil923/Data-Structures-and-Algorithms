// Question Link: https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
// Difficulty Level : Medium
// Input: ar1[] = {10};
//       ar2[] = {2, 3};
// Output: ar1[] = {2}
//        ar2[] = {3, 10}  
// Expected Time complexity : O(N1*N2)
// Expected Space Complexity : O(1)

// Question Undesrstanding : We are given two sorted arrays. 
// We need to merge these two arrays such that the initial numbers (after complete sorting) are in the first array and the remaining numbers are in the second array 
// It's not about just printing otherwise it can be done in O(N1+N2) with O(1) space complexity by merge sorting method

// Naive Approch : Take temprary array of size (N1 + N2) and then using merge method in merge sorting store elements in temprary array S.C-O(N1+N2) for extra array
// Better Approch : Using insertion Sort
// Traverse first array if element arr1[i] is larger than arr2[0] swap them and find correct position for arr2[0] insecond array through insertion sort
// T.C-O(N1*N2) S.C-O(1)

#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int n1,int arr2[],int n2)
{
	for(int i=0;i<n1;i++)
	{
		// e.g arr1[] = { 2 , 3 , 4 } arr2[] = { 1 , 5 , 6 } now will swap 2 & 1 and then fix the position of 2 in 2nd array
		if(arr1[i] > arr2[0])
		{
			swap(arr1[i],arr2[0]);
			
			// insertion sort through second array
			int key = arr2[0];
			int j = 1;
			
			// loop will traverse until first element gets higher element than it in array
			while ( j < n2 && arr2[j] < key)
			{
				arr2[j-1]=arr2[j];
				j++;
			}
			arr2[j-1] = key;
		}		
	}
	
	for(int i=0;i<n1;i++) cout<<arr1[i]<<" ";
	for(int i=0;i<n2;i++) cout<<arr2[i]<<" ";
}

//main function
int main()
{
 	int n1,n2;cin>>n1>>n2;
 	int arr1[n1],arr2[n2];
 	for(int i=0;i<n1;i++) cin>>arr1[i];
 	for(int i=0;i<n2;i++) cin>>arr2[i];
 	
 	merge(arr1,n1,arr2,n2);

 	return 0;
}



