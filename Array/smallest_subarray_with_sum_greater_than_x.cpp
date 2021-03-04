// Question Link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
// Difficulty Level : Easy
// e.g Input: 1 10 5 2 7 x=10 output: 1 {10}
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(1) 

//Naive approch will be take each subarray and compute it's size each time. Time Complexity: O(N^2)
// Approch for expected time complexity and space complexity:-
// Traverse array and keep track of left and right boundries which are of subarray whose sum is greater than x.


#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int n,int x)
{	
	// sum=temparary sum
	// left,right=boundries of subarray
	// ans= final minimum result
	int left=0,right=0,ans=INT_MAX,sum=0;
	
	for(int i=0;i<n;i++)
	{
		//keep on adding elements until we get sum greater than x
		if(sum<=x)
		{
			sum+=a[i];
			right++;
		}
		if(sum>x)
		{
			//iterate until sum is greater than x once it'll get less come out of loop
			while(sum>x)
			{
				ans=min(right-left,ans);
				sum-=a[left];
				left++;
			}
		}
	}
	
	return ans;
	
}

//main function
int main()
{
 	int n,x;cin>>n>>x;
 	int a[n];
 	for(int i=0;i<n;i++) cin>>a[i];
 	
 	cout<<"Smallest subarray size having sum greater than x is "<<solve(a,n,x);
 	
 	return 0;
}


