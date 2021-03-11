// Question Link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// Difficulty Level : Easy
//Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2
// Expected Time complexity : O(N)
// Expected Space Complexity : O(N)

// Naive Approch : with two nested for loops find pair with given sum T.C-O(N^2)
// Better Approch : Store frequency of each element and for each element find if sum-arr[i] present in array if yes then pairs += frequency[arr[i]]
// in this approch final no. of pairs will be half of count because we have done count twice for each pair


#include<bits/stdc++.h>
using namespace std;

int pairsSum(int arr[],int n,int sum)
{
	unordered_map <int,int> up;
	
	for(int i=0;i<n;i++)
		up[arr[i]]++;
		
	int pairs=0;
	
	for(int i=0;i<n;i++)
	{
		int count = up[sum-arr[i]];
		
		if(count)
		{
			if( sum/2 != arr[i])
				pairs += count;
				
			// if 2* arr[i] = sum then element will make pair with frequency[arr[i]]-1 elements
			else	
				pairs += count-1;
		}
	}
	
	// each pais has been counted twice
	return pairs/2;
}

//main function
int main()
{
 	int n,k;cin>>n>>k;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];

	cout<<"Pairs with given sum are :"<<pairsSum(arr,n,k);
 	return 0;
}



