// Question Link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Difficulty Level : Medium
// e.g Input: 2 2 1 2 0 1 output: 0 1 1 2 2 2
// Time complexity : O(N) [Traversing array once]...optimal approch
// Space Complexity : O(1) [Only use of temporary variable]


// Naive approch - sort array...Time complexity:O(NlogN)
// Better approch - count no. of 0's ,1's,2's and print accordingly
// Different one - Dutch National Flag Approch..refer GFG
// Basic understanding : we'll have 3 variables with us low,medium,high.Divide array into 4 different parts first from start of array to low,one from low to medium,next from medium to high,third from high to end of array.
                                 

#include<bits/stdc++.h>
using namespace std;

void sort(int arr[],int n)
{
	int low=0,medium=0,high=n-1;
	while(medium<=high)
	{
		switch(arr[medium])
		{
			case 0:
				swap(arr[low],arr[medium]);
				medium++;
				low++;
				break;
			case 1:
				medium++;
				break;
			case 2:
				swap(arr[medium],arr[high]);
				high--;
		}
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
 	
 	sort(arr,n);
 	print_Array(arr,n);
 	return 0;
}


