// Comsidering array elements are not duplicate

// For naive approch refer previous code in this question both the arrays are sorted beforehand
// Expected Time Complexity : O(N+M)
// Expected Space Complexity : O(1)
// Approch is similar to merge sort. Keep on treversing both the arrays if similar element occurs take it only once


// Note: Same code can be applied to unsorted elements diffrence being first need to sort both the arrays
// Time complexity(Unsorted) : NlogN + MlogM
// space complexity : O(1)

// Approches for unsorted arrays :
// 1. Use Hashing : idea being store array elemnts of any of one array into hash and check for another. Time Complexity: O(N+M) Space Complexity : O(N)
// 2. Searching and Sorting : idea being sort one array and find each element from next array with the use of binary search. Time Complexity : NlogN + MLogN Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;

vector<int> union_Array(int arr[],int n,int brr[],int m)
{
	vector<int> ans;
	int i=0,j=0;
	
	//loop will iterate until atleast one of array has not been ended
	while(i<n && j<m)
	{
		if(arr[i]>brr[j])
		{
			ans.push_back(brr[j]);
			j++;
		}
		else if(arr[i]<brr[j])
		{
			ans.push_back(arr[i]);
			i++;
		}
		else
		{
			//same array element
			ans.push_back(arr[i]);
			i++;j++;
		}
	}
	
	//if array has not ended yet
	while(i<n)
	{
		ans.push_back(arr[i]);
		i++;
	}
	
	while(j<m)
	{
		ans.push_back(brr[j]);
		j++;
	}
	
	return ans;
}

//main function
int main()
{
 	//taking input for array
	int n,m;cin>>n>>m;
 	int arr[n],brr[m];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	for(int i=0;i<m;i++) cin>>brr[i];
 	
 	vector<int> ans=union_Array(arr,n,brr,m);
 	for(auto it:ans)
 		cout<<it<<" ";
 	cout<<"\nNo. of Unique elemnts are "<<ans.size();
 	
 	
 	return 0;
}


