// Question Link: https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
// Difficulty Level : Medium
// Input: ar1[] = {10};
//       ar2[] = {2, 3};
// Output: ar1[] = {2}
//        ar2[] = {3, 10}  
// Expected Time complexity : O(N1+N2 log(N1+N2))
// Expected Space Complexity : O(1)

// Previously we have discussed about 2 approches
// In this will discuss about optimal approch i.e Gap method
// Approch : we have gap varible gap= (N1+N2)/2 each time this gap will become half until it's become 0
// with the current gap will check if arr[i] < arr[i+gap] if not swap those number and keep moving ahead 


#include<bits/stdc++.h>
using namespace std;

void mergeWithGap(int arr1[],int n1,int arr2[],int n2)
{
	double gapFloat = (double(n1+n2)/2.0);
		
	int gap= ceil(gapFloat);

	while(gap>0)
	{
		int i,j;
		// both imits are in first array
		for(i=0; i+gap<n1; i++)
		{
			if(arr1[i] > arr1[i+gap])
				swap(arr1[i],arr1[i]);
		}
		
		// first limit in first array and second in second array
		for(j= gap>n1 ? gap-n1:0 ; i < n1 && j<n2 ; i++,j++)
		{
			if(arr1[i] > arr2[j])
				swap(arr1[i],arr2[j]);
		}
		
		// both imits are in second array
		if (j<n2)
		{
			for(j=0;j+gap<n2;j++)
			{
				if(arr2[j] > arr2[j+gap])
					swap(arr2[j],arr2[j+gap]);
			}
		}
		
		// if gap is 1 with below formula loop will run infinite times at gap = 1 
		if(gap==1)
			break;
		gap = (gap/2) + (gap%2);
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
 	
 	mergeWithGap(arr1,n1,arr2,n2);

 	return 0;
}



