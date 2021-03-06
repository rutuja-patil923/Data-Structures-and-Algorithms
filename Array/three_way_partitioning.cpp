// Question Link: https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/
// Difficulty Level : Medium
// e.g Input: N = 5 A[] = {1, 2, 3, 3, 4} [a, b] = [1, 2] output: 1
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(1) 

// Question Understanding : partition array into 3 parts such that first part will contain all elements less than a second will contain elements in between a nd b , last part will contain elements greater than k
// in ouput return 1 if it's possible and make all swappings in place and modify array
// anyhow with swappings we can do partitioning thing is need to use efficient algorithm for modifying array

// Naive approch : sort array in ascending order Time complexity : O(NLogN)
// Better Approch : Use Dutch National Flag method used in sorting array containing only 0,1,2 same concept can be applied with slight changes.



#include<bits/stdc++.h>
using namespace std;

void print_Array(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

void threeWayPartition(int arr[],int n,int a,int b)
{
	int low=0,medium=0,high=n-1;
	while(medium<=high)
	{
		if(arr[medium]<a)
		{
			swap(arr[low],arr[medium]);
			low++;
			medium++;
		}
		else if(arr[medium]>=a && arr[medium]<=b)
		{
			medium++;
		}
		else
		{
			swap(arr[medium],arr[high]);
			high--;
		}
	}
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	int a,b;cin>>a>>b;
 	
 	threeWayPartition(arr,n,a,b);
 	print_Array(arr,n);
 	
 	return 0;
}


