#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high)
{
	int x = arr[high],i=low;

	for(int j=low;j<high;j++)
	{
		if(arr[j] <= x)
		{
			swap(arr[j],arr[i]);
			i++;
		}
	}

	swap(arr[i],arr[high]);
	return i;
}

int KthSmallest(int arr[],int low,int high,int K)
{

	if(K > 0 && K<=(high-low+1))
	{
		int position = partition(arr,low,high);

		if(position-low == K-1)
			return arr[position];
		if(position-low > K-1)
			return KthSmallest(arr,low,position-1,K);
		return KthSmallest(arr,position+1,high,K-(position-low+1));
	}
}

int main()
{
	int N,K;
	cin>>N>>K;

	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	cout<<KthSmallest(arr,0,N-1,K);
}
