// Question Link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
// Difficulty Level : Medium 
// e.g Input: 3 5 1 8 2 output: 8 1
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) [Only use of temporary variable for storing maximum and minimum]


// Naive Approch: Declare two varibles max and min and by checking if conditions find minimum and Maximum
// Total Comparisons in Naive approch : 2*(N)

// Better Approch : replace second if condition with else for finding minimum so that no. of comparions will decrease
// Code snippet :
// for loop {        if(array_element>max) max_element finding     else min element finding }
// Total comparisons : Best Case [All array elements are sorted]-(N-2)+1  Worst Case [Descending Order]-1+ 2*(N-2)....[At starting we're doing comparisons of first two elements and then remaining N-2 elements]

// Optimal Approch : 1) Divide and Conquer 2) Compare in pairs
// Total no. of comparisons can be calculated using Master algorithm : 
// T(N)=T(N/2)+T(N/2)+1 ,T(2)=1,T(1)=0  ....[refer finding time complexity of recursive algorithms using master algorithm]
// Total no. of comparisons will be then (3*(N/2))-2...[Divide and conquer algorithm]


#include<bits/stdc++.h>
using namespace std;

// structure to store 2 data types at a time
struct minmax
{
	int mini;
	int maxi;
};

struct minmax divide_and_Conquer(int arr[],int left,int right)
{
	struct minmax mmRes,mmLeft,mmRight;
	
	//2 array elements remaining
	if(right==left+1)
	{
		if(arr[left]>=arr[right])
		{
			mmRes.mini=arr[right];
			mmRes.maxi=arr[left];
			return mmRes;
		}
	}
	//only 1 array element
	if(right==left)
	{
		mmRes.mini=arr[left];
		mmRes.maxi=arr[left];
		return mmRes;
	}
	
	
	int mid=(left+right)/2;
	
	mmLeft= divide_and_Conquer(arr,left,mid);
	mmRight=divide_and_Conquer(arr,mid+1,right);
	
	mmRes.mini=min(mmLeft.mini,mmRight.mini);
	mmRes.maxi=max(mmLeft.maxi,mmRight.maxi);
	
	return mmRes;
}

//main function
int main()
{
 	//Taking input of array and no. of array elements
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	struct minmax res=divide_and_Conquer(arr,0,n-1);
 	cout<<"Maximum element in array:"<<res.maxi<<" "<<"Minimum element in array:"<<res.mini;
	
 	return 0;
}

