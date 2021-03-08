// Question Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

// Code will be same as median for two sorted arrays with different size only diffrence in if conditions as follows:

#include<bits/stdc++.h>
using namespace std;

int arr[1000],brr[1000];
int n;

int medianSorted(int low,int high)
{
	// binary search loop 
	while(low<=high)
	{
		// no. of elements from first array
		int cut1=(low+high)/2;
		
		// no. elements from second array
		// in diffrent size array we were taking it as n1+n2 /2
		// now size is equal so n1+n2=2n/2=n
		int cut2=n-cut1;
		
		
		// if any one of the array has crossed it's limit we''ll set accordingly 
		
		// last element in first part of array 1 i.e before cut1
		int l1= (cut1==0 ? INT_MIN:arr[cut1-1]);
		// last element in first part of array 2
		int l2= (cut2==0 ? INT_MIN:brr[cut2-1]);
		// first element in second part of array 1 i.e after cut 1
		int r1=  (cut1==n ? INT_MAX:arr[cut1]);
		// first element in second part of array 2 
		int r2= (cut2==n ? INT_MAX:brr[cut2]);
		
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
			// as size of both arrays is equal size of combined array will always be even. Hence no condition for odd elements.
			int left=max(l1,l2);
			int right=min(r1,r2);
			return (left+right)/2;
		}
		
	}
}

//main function
int main()
{
 	// size of both arrays
 	// variables declared globally
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) cin>>brr[i];
	
	
	cout<<"The median is "<<medianSorted(0,n-1);
	
	
 	return 0;
}


