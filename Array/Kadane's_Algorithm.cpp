// Note: Important concept to learn 
// use : mainly used for question like maximum sum of contigous subarray

// Question Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Difficulty Level : Basic
// e.g Input: 1 -1 3 2 7 output: 12 [3+2+7]
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) 


#include<bits/stdc++.h>
using namespace std;

int kadane_algo(int arr[],int n)
{
	//local_sum will store sums temprarily while global_sum will store the answer
	int local_sum=0,global_sum=INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		//will check if taking current array element is beneficial or not
		local_sum=max(arr[i],local_sum+arr[i]);
		
		if(local_sum>global_sum)
			global_sum=local_sum;
	}
	
	return global_sum;
}

//main function
int main()
{
 	//taking input for array
	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<"largest sum of contiguous subarray is "<<kadane_algo(arr,n);
 	return 0;
}


