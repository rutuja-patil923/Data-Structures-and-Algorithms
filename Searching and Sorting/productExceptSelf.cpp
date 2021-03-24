// Question Link : https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1
// Input:
// N = 5
// A[] = {10, 3, 5, 6, 2}
// Output:
// 180 600 360 300 900
// Explanation: 
// For i=0, P[i] = 3*5*6*2 = 180.
// For i=1, P[i] = 10*5*6*2 = 600.
// For i=2, P[i] = 10*3*6*2 = 360.
// For i=3, P[i] = 10*3*5*2 = 300.
// For i=4, P[i] = 10*3*5*6 = 900.

// Expected Time Complexity : O(N)
// Expected Space complexity : O(1) 

// Approch : for each element we need product till left and till right 
// Naive : create two arrays left and right which will store products left and right. O(N) O(N)
// Efficient : store left product till that index into temp variable

//_______________________________________________________________________________________________________________

#include<bits/stdc++.h>
using namespace std;

void productExceptSelf(int nums[],int N)
{
	int left = 1,right = 1;

	int product[N]={1};

	for(int i=0;i<N;i++)
	{
		product[i] = left ;
		left *= nums[i]; 
	}

	for(int i = N-1;i>=0;i--)
	{
		product[i] *= right;
		right *= nums[i];
	}

	for(int i=0;i<N;i++) cout<<product[i]<<" ";
}

int main()
{
	int N;cin>>N;
	int nums[N];
	for(int i=0;i<N;i++) cin>>nums[i];

	productExceptSelf(nums,N);
}
