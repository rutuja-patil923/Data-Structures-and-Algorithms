// Question Link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
// Difficulty Level : Medium
// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Expected Time complexity : O( N1 + N2 + N3 )
// Expected Space Complexity : O( N1 + N2 + N3)

// Question Understanding : 3 Sorted array will be given we need to find common elements in all 3

// Naive approch : with 3 nested loops we can find common elements.
// Optimal Approch 1 : traverse all 3 arrays once Use Merge sorting method with just little modification
// Optimal Approch 2 : take one by one element from array having minimum length and apply binary search on remaining arrays 
// Suppose minimum array length is 

#include<bits/stdc++.h>
using namespace std;

void commonElements(int arr[],int n1,int brr[],int n2,int crr[],int n3)
{
	// 3 iterators
	int i=0,j=0,k=0;
	
	// loop will iterate until any of the arrays ends
	while( i<n1 && j<n2 && k<n3)
	{
		// at first comparison will occur only between two arrays
		if(arr[i] < brr[j])
			i++;
		else if(arr[i] > brr[j])
			j++;
		else if(crr[k] < brr[j])
			k++;
		else if(crr[k] > brr[j])
			i++;
			
		// common element found
		// should have condition to check if common element has already been included in resultant array
		else if(crr[k] == brr[j])
		{
			cout<<arr[i]<<" ";
			i++;
			j++;
			k++;
		}	
	}
}

//main function
int main()
{
 	int n1,n2,n3;cin>>n1>>n2>>n3;
 	int arr[n1],brr[n2],crr[n3];
 	for(int i=0;i<n1;i++) cin>>arr[i];
 	for(int i=0;i<n2;i++) cin>>brr[i];
 	for(int i=0;i<n3;i++) cin>>crr[i];
 	
 	commonElements(arr,n1,brr,n2,crr,n3);

 	return 0;
}



