// Question Link: https://www.geeksforgeeks.org/counting-inversions/
// Difficulty Level : Hard
// Input: arr[] = {8, 4, 2, 1} Output: 6 ...{inversions : (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1)}
// Expected Time complexity : O(NlogN)
// Expected Space Complexity : O(N)

// Question Understanding : We need to count inversions. inversion means if a[i] > a[j] when i < j. Count such inversions in whole array

// Naive approch : with the use of 2 nested loops count such inversions T.C-O (N^2)
// Optimal approch : Use of merge sorting 
// in merge sorting we merge two parts of array by simply traversing both arrays. 
// e.g array 1 ={2,3,4} array 2 ={1,5} now if i=0 , while merging 1 will come first in resultant array but it means all elements in first array are greater than 1
// i.e (mid-i) elements will be inversion count when we find smaller element in second part of the array 
// count inversions while merging arrays each time.


#include<bits/stdc++.h>
using namespace std;


int merge(int arr[],int left,int mid ,int right, int temp[])
{
	int inv_cnt = 0;
	
	// first part and second part starting
	int i=0,j=mid;
	
	// resultant array iterator
	int k=0;
	
	// merging sorted arrays into resultant array
	while(i<=mid-1 && j<=right)
	{
		// if array element in first part is smaller than another count will not increase
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i];
			i++;
		}
			
		// here second part contains smaller element now it'll contribute to inversion count	
		else
		{
			// only elemnets from i are greater than element at j
			inv_cnt += mid - i;
			temp[k++]=arr[j];
			j++;
		}
	}
	
	// if any element is remaining from first part of array
	while(i<=mid-1)
	{
		temp[k++]=arr[i];
		i++;
	}
	
	// if any element is remaining from second part of array
	while(j<=right)
	{
		temp[k++]=arr[j];
		j++;
	}
	
	// copying resultant array to main array
	for( i=left ; i<=right ; i++)
		arr[i] = temp[i];
		
	return inv_cnt;
}

int countInversions(int arr[],int left,int right,int temp[])
{
	// contains total inversion count
	int inversion_cnt=0;
	
	if(left < right)
	{
		int mid = (left + right)/2;
		
		// dividing whole array into 2 parts
		inversion_cnt += countInversions(arr,left,mid,temp);
		inversion_cnt += countInversions(arr,mid+1,right,temp);
		
		// combining whole array again
		inversion_cnt += merge(arr,left,mid+1,right,temp);			
	} 
	
	return inversion_cnt;
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	int temp[n];
	cout<<"No. of Inversions: "<<countInversions(arr,0,n-1,temp);

 	return 0;
}



