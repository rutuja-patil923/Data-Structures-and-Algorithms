// Question Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
// Difficulty Level : Hard
// e.g Input: ar1[] = {-5, 3, 6, 12, 15} ar2[] = {-12, -10, -6, -3, 4, 10} output: The median is 3
// Expected Time complexity : O(logN) [Traversing array once]
// Space Complexity : O(1) 

// Question Understanding : we need to find median of array after merging both sorted arrays
// Median is middle element in sorted array in odd no. of elements case if no. of elements are even then median will be average of two elements.

// Brute Force approch : Make array of size N1 + N2 sort it and find middle T.C- O((N1+N2)log(N1+N2)) S.C-O(N1+N2)
// Better Approch : as elements in each of array are already sorted we can use this and merge them like in merge sort traversing both the arrays with T.C - O(N1+N2) S.C-O(N1+N2)
// Optimal Approch : Space complexity in better approch can further improve by keeping one counter and if counter reaches to Median index calculate median. S.C-O(1)
// Best approch with expected time complexity i.e O(logN) : as time complexity logN so Binary search can be used here

// More clear and detailed explanation is here : https://youtu.be/yD7wV8SyPrc 

// Approch : so basically we're finding value of cut in any of the array which denotes how many numbers from first array and second array should be taken in resultant array to find median

#include<bits/stdc++.h>
using namespace std;

int arr[1000],brr[1000];
int n1,n2;

int medianSorted(int low,int high)
{
	// binary search loop 
	while(low<=high)
	{
		// no. of elements from first array
		int cut1=(low+high)/2;
		
		// no. elements from second array
		int cut2=(n1+n2)/2-cut1;
		
		
		// if any one of the array has crossed it's limit we''ll set accordingly 
		
		// last element in first part of array 1 i.e before cut1
		int l1= (cut1==0 ? INT_MIN:arr[cut1-1]);
		// last element in first part of array 2
		int l2= (cut2==0 ? INT_MIN:brr[cut2-1]);
		// first element in second part of array 1 i.e after cut 1
		int r1=  (cut1==n1 ? INT_MAX:arr[cut1]);
		// first element in second part of array 2 
		int r2= (cut2==n2 ? INT_MAX:brr[cut2]);
		
		// if last element in first array in array 1 is greater which means array should move towards left
		if(l1>r2)
		{
			high=cut1-1;
		}
		
		// if last element in second array is greater the array should move towards right
		else if(l2>r1)
		{
			low=cut1+1;
		}
		else
		{
			// if combined array is having even elements then median will be average of middle two elements
			if((n1+n2)%2==0)
			{
				int left=max(l1,l2);
				int right=min(r1,r2);
				return (left+right)/2;
			}
			
			// if combined array having odd elements which means median will be middle element.
			// when partitioning combined array one element will be extra in one of the parts
			// 
			else
			{
				return min(r1,r2);
			}
		}
		
	}
}

//main function
int main()
{
 	// size of both arrays
 	// variables declared globally
	cin>>n1>>n2;
	for(int i=0;i<n1;i++) cin>>arr[i];
	for(int i=0;i<n2;i++) cin>>brr[i];
	
	// finding cut in smaller size array
	if(n1>n2)
	{
		swap(n1,n2);
		swap(arr,brr);
	}
		
	
	cout<<"The median is "<<medianSorted(0,n1-1);
	
	
 	return 0;
}


