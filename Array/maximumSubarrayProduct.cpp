// Question Link: https://www.geeksforgeeks.org/maximum-product-subarray/
// Difficulty Level : Hard
// e.g Input: arr[] = {6, -3, -10, 0, 2} output: 180
// Expected Time complexity : O(N) 
// Space Complexity : O(1) 

// Question Understanding : We need to find subarray with maximum product. Array contains +ve,-ve and 0 as array elements. 
// Naive approch : Take each subarray starting from particular index and then calculate product and compare it with maximum. T.C-O(N^2)..[2 for loops]
// Efficient approch : This question can appear same as maximum contiguous subarray sum (kadane's algorithm) 
// but this array contains -ve elements as well so if one -ve element is present at position i and one element is at position j far from previous one so it might be possible
// that by taking those two elements product will become maximum. Problem is with -ve numbers.
// now we'll keep track of maximum product till position i, minimum product till i(this is for negative elements so that if -ve till end multiplying with another -ve will make it positive)




#include<bits/stdc++.h>
using namespace std;

int maximumSubarrayProduct(int arr[],int n)
{
	// maximum product till i
	// always +ve
	int max_end=arr[0];
	
	// minimum product till i
	// -ve or 1
	int min_end=arr[0];
	
	// stores ans.
	int global_max=INT_MIN;
	
	// 3 types of array elements either +ve,-ve or 0
	for(int i=1;i<n;i++)
	{
		// if element is +ve then multiplying max_end will increase it's value
		// multiplying with min_end will decrease it's value so that when in future -ve element will occur multiply with min_end will give max ans.
		if(arr[i]>0)
		{
			max_end=max_end*arr[i];
			min_end=min(min_end*arr[i],1);		
		}
		
		// -ve element multiplying with min_end will give maximum ans. rather than max_end
		else if(arr[i]<0)
		{
			int temp=max_end;
			max_end=max(min_end*arr[i],1);
			min_end=temp*arr[i];
		}
		
		// array element is 0 no contribution in product 
		// all calculation will start from first
		else
		{
			max_end=1;
			min_end=1;
		}
		
		// will store maximum ans. till i
		if(max_end>global_max)
			global_max=max_end;
	}
	
	return global_max;
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<maximumSubarrayProduct(arr,n);
 	
 	return 0;
}


