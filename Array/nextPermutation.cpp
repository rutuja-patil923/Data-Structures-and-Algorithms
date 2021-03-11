// Question Link: https://leetcode.com/problems/next-permutation/
// Difficulty Level : Medium
// Input: nums = [1,2,3] Output: [1,3,2]
// Expected Time complexity : O(NlogN)
// Expected Space Complexity : O(1)

// Question Understanding : find next permutation e.g {2 4 5} next permutation will be {2 5 4}, {8 7 6 5} output will be {5 6 7 8}

// Approch : By observation, traverse from right of array until next element is greater. If element is smaller than previous stop at that position. Suppose it's i
// in the processed array find nearest greater element of arr[i] and swap those number. Now for remaining array sort array from i+1 to right.
// in worse condition all digits are descending order for sorting the T.C-O(NlogN)

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(int arr[],int n)
{
	// to check if next smaller element and pos to store position
	int flag=0,pos;
	
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]<arr[i+1])
		{
			flag=1;
			pos=i;
			break;
		}
	}
	
	// all digits are in descending order
	if(!flag)
		sort(arr,arr+n);
		
	int minDiff=INT_MAX;
	
	// in processed array nearest greater element position
	int store=pos;  
	
	// now find nearest greater element of arr[pos]
	for(int i= pos+1;i<n;i++)
	{
		if(arr[i]-arr[pos] < minDiff && arr[i]-arr[pos]>0) 
		{
			//cout<<minDiff<<" "<<endl;
			minDiff=arr[i]-arr[pos];
			store=i;
			//cout<<"store"<<store<<endl;
		}
	}
	
	//cout<<pos<<" "<<store<<endl;
	swap(arr[pos],arr[store]);
	
	sort(arr+pos+1,arr+n);
	
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
 	
 	nextPermutation(arr,n);
 	print_Array(arr,n);

 	return 0;
}



