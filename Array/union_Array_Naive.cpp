// Question Link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// Difficulty Level : Basic
// e.g Input: arr[]=1 2 3 4 5 brr[]=1 2 3 output: 5..[No. of unique elements]
// Expected Time complexity : O((n+m)log(n+m))
// Expected Space Complexity : O(n+m)

// By considering expected time complexity and space complexity simple approch can be to store all array elements from both the arrays in single array and sort them and while taking count just take count of elements only once evn if adjacent elemnts are same



#include<bits/stdc++.h>
using namespace std;

int union_Array(int arr[],int n,int brr[],int m)
{
	//make temoparrary array of size n+m
	int temp_Array[n+m],k=0;
	for(int i=0;i<n;i++) temp_Array[k++]=arr[i];
	for(int i=0;i<m;i++) temp_Array[k++]=brr[i];
	
	//STL sort function
	sort(temp_Array,temp_Array+n+m);
	
	// starting loop from second element  i.e index 1 hence initial count is 1 for first element itself
	int count=1;
	
	for(int i=1;i<n+m;i++)
	{
		//checking if element occurs previously
		if(temp_Array[i]==temp_Array[i-1])
			continue;
			
		count+=1;
	}
	
	return count;
}

//main function
int main()
{
 	//taking input for array
	int n,m;cin>>n>>m;
 	int arr[n],brr[m];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	for(int i=0;i<m;i++) cin>>brr[i];
 	
 	cout<<"No. of unique elements in both array are "<<union_Array(arr,n,brr,m);
 	
 	return 0;
}


