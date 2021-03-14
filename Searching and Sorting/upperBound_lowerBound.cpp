// lower_bound and upper_bound are two STL functions in C++ library
// lower_bound : i) if no. exists in array it will return first occurrence of element
//               ii) if no. not exists in array it will return next immediate greater element index
// upper_bound : i) if no. exists in array it will return index of last occurrence of element + 1
//               ii) if it not exists it will return next immediate greater element index

// below is implementation of both functions
// Time Complexity : log(N)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[],int n,int x)
{
	int low = 0;
	int high = n-1;

	while(low<high)
	{
		
		int mid = (low + high)/2;
	
		if(arr[mid]>=x)
			high = mid;
		else
			low = mid + 1;
			
		//cout<<low<<" "<<high<<endl;
	}

	return low;
}

int upperBound(int arr[],int n,int x)
{
	int low = 0;
	int high = n-1;

	while(low<high)
	{
		int mid = (low + high)/2;

		// Be careful about this condition :(
		if(arr[mid]<=x)
			low = mid + 1;
		else
			high = mid;
	}

	return low;
}

int main()
{
	int n;cin>>n;

	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	int x;cin>>x;
	
	int lower = lowerBound(arr,n,x);
	int upper = upperBound(arr,n,x);

	cout<<"Lower Bound : "<<lower<<" "<<"Upper Bound : "<<upper;
}
