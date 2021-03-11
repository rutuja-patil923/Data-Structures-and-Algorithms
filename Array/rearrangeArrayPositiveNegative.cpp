// Question Link: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
// Difficulty Level : Hard
// Input:  arr[] = {1, 2, 3, -4, -1, 4} Output: arr[] = {-4, 1, -1, 2, 3, 4}
// Expected Space Complexity : O(1)

// Question Understanding : We need to rearrange array such that alternative position contains +ve and -ve numbers without changing order of elements
// if any of them are larger in number keep them at end of array

// Naive Approch : if it is allowed to use extra space then it can be done easily done by storing -ve and +ve elements in 2 separate arrays and combining in resultant array
// Better Approch : with O(1) extra space we can sort array and swap elements at alternate positions T.C-O(NlogN)
// Another Approch : with simply two nested loops we can find position of misplaced element and then swap it with opposite sign element in remaining array
// but problem with this approch will be order of elements will change
// to keep order as it is right rotation can be useful.

#include<bits/stdc++.h>
using namespace std;

void rightRotate(int arr[],int misplaced,int current)
{
	// storing last element 
	int temp=arr[current];
	
	for(int i=current; i>misplaced;i--)
		arr[i]=arr[i-1];
	arr[misplaced]=temp;
}

void rearrangeAlt(int arr[],int n)
{
	// initializing position of misplaced element as -1
	int misplaced=-1;
	
	for(int i=0;i<n;i++)
	{
		// if array contains misplaced element
		if(misplaced >= 0)
		{
			// checking for element of opposite sign to misplaced element
			if((arr[i]>0 && arr[misplaced]<0) || (arr[i]<0 && arr[misplaced]>0))
			{
				// we can do direct swapping also
				// but it'll affect order of elements hence right rotation
				rightRotate(arr,misplaced,i);
				
				// now next misplaced element will appear at (misplaced +2) th position
				
				// if elements were not adjacent
				if(i-misplaced>=2)
					misplaced += 2;
				else
					misplaced = -1;
				
			}
		}
		
		// checking if current array element is misplaced
		// assumption is -ve elements placed at even position and +ve at odd
		if(misplaced == -1)
		{
			if((arr[i]>0 && i%2==0) || (arr[i]<0 && i%2==1))
				misplaced=i;
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
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	rearrangeAlt(arr,n);
 	print_Array(arr,n);

 	return 0;
}



