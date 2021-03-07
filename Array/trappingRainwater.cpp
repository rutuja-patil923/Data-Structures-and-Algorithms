// Question Link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Difficulty Level : Medium
// e.g Input: {6,9,9} output: 0
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(N)

// Question Understanding : if we draw each bar or building and see how much water each building can hold 
// water = min(leftmost max height,rightmost max height)-height of building
// now question asks us to find leftmost max and rightmost max height building for each building

// Naive approch : for rach building will traverse left and right and find maximum height buildings which will take O(N^2) time
// Better approch : Make two arrays left and right and store for each height leftmost max and rightmost max height T.C-O(N) S.C-O(N)..[for left and right array]
// Another approch : same question can be solved using stack as well..[refer GFG]
// More optimal approch : even though creating left array and right array is better approch but still space complexity can be optimized to O(1)
// in this we will use two pointer approch 

#include<bits/stdc++.h>
using namespace std;

int trappingWater(int arr[],int n)
{
	// stores leftmost max height of building for each building  
	int leftmax=0;
	
	// stores rightmost max height of building for each building
	int rightmax=0;
	
	// left index
	int left=0;
	
	// right index
	int right=n-1;
	
	// stores ans
	int ans=0;
	
	while(left<=right)
	{
		if(arr[left]<=arr[right])
		{
			if(arr[left]>leftmax)
				leftmax=arr[left];
			else
				// intution : without comparing right part we're directly substracting it from left why?
				// ans will be before coming to this loop we have checked already that arr[right]>=arr[left]
				// it means some building with greater height is present at right!!!
				ans+= leftmax-arr[left];
			left++;
		}
		else if(arr[right]<arr[left])
		{
			if(arr[right]>rightmax)
				rightmax= arr[right];
			else
				ans+= rightmax-arr[right];
			right--;
		}
	}
	
	return ans;
	
} 

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<trappingWater(arr,n);
 	
 	return 0;
}


