// Question Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#
// Difficulty Level : Easy
// e.g Input: N = 8, M = 5 A = {3, 4, 1, 9, 56, 7, 9, 12} output: 6
// Expected Time complexity : O(NlogN) 
// Expected Space Complexity : O(1) 

//Question Understanding: So basically we need to choose e elements from array in which diffrence between maximum and minimum element is minimum.

// Approch : By considering expected time complexity sorting will be used
// Only M packets required so sliding window technique can be usde effectively here
// why ? if we choose random elements diffrence will not remain minimum.

#include<bits/stdc++.h>
using namespace std;

int chocolateDistribution(int arr[],int n,int m){
	
	// if no. of chocolates or students are 0
	if(n==0 || m==0)
		return 0;
	
	// if no. of students greater than no. packets
	if(n<m)
		return -1;
	
	sort(arr,arr+n);
    
    // no need to travel window first because minimum and maximum element in each window are fixed.
    int ans=arr[m-1]-arr[0];
    
    for(int i=1,j=m;j<n;j++,i++)
    {
        ans=min(ans,arr[j]-arr[i]);
    }
    
    return ans;
}

//main function
int main()
{
 	int n,m;cin>>n>>m;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<chocolateDistribution(arr,n,m);
 	return 0;
}


