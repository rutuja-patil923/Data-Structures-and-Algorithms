// Question Link: https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
// Difficulty Level : Hard
// e.g Input: arr1[] = { 4, 5, 6, 7, 8, 4, 4 }  k = 3 output: Number=4 count=3
// Expected Time complexity : O(NK)
// Expected Space Complexity : O(K)

// Question Understanding : we need to find numbers such that their count which should be greater than n/k 
// Naive approch : Using two nested for loops find count of each element in array T.C-O(N^2) S.C-O(1)
// Better approch : if constraints are quite less then frequency array can be sued to store the frequency of each element T.C-O(N) S.C-O(N)
// but if constraints are high then map can be used T.C-O(NlogN)

// Optimal approch : 
// there are no more than k-1 elements which will satisfy given condition why? suppose n=15 k=3 n/k=5 frequency greater than n/k means greater than 5
// suppose take least as 6  there can't be 3 elements with 6 frequency as 6*3=18 > 15 
// now will create one array of max size k-1 and store frequency of each element and store potential elements and check if they contain frequency > n/k
// T.C-O(NK) S.C-O(K-1)


#include<bits/stdc++.h>
using namespace std;

typedef struct freq
{
	int element;
	int count;
}freq;

void freqGreater_n_by_k(int arr[],int n,int k)
{
	// array to store potential elements
	freq temp[k-1];
	
	// Initializing frequency of array elements as 0
	for(int i=0;i<k;i++) temp[i].count=0;
	
	for(int i=0;i<n;i++)
	{
		// to check if condition fullfilled
		int flag=0;
		
		// check if array element already present as potential candidate
		for(int j=0;j<k;j++)
		{
			if(temp[j].element == arr[i])
			{
				temp[j].count++;
				flag=1;
				break;	
			}	
		}
		
		// array element not present then store it
		if(!flag)
		{
			flag=0;
			for(int j=0;j<k;j++)
			{
				if(temp[j].count==0)
				{
					temp[j].element=arr[i];
					temp[j].count=1;
					flag=1;
					break;
				}
			}
		}
		
		// array has no space to store
		if(!flag)
		{
			for(int j=0;j<k;j++)
				temp[j].count--;
		}
			
	}	
	
	// checking if potential elements can follow condition given in question
	for(int i=0;i<k;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(temp[i].element==arr[j])
				cnt++;
		}
		
		if(cnt > n/k)
			cout<<"Number : "<<temp[i].element<<" Count : "<<cnt<<endl;
	}
}

//main function
int main()
{
 	int n,k;cin>>n>>k;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	freqGreater_n_by_k(arr,n,k);

 	return 0;
}



