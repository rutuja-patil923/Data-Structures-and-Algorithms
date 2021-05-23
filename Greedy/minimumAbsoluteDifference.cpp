#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;cin>>N;

	int arr[N],brr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	for(int i=0;i<N;i++)
		cin>>brr[i];

	sort(arr,arr+N);
	sort(brr,brr+N);

	int sum=0;
	for(int i=0;i<N;i++)
		sum += abs(arr[i]-brr[i]);

	cout<,sum;
}