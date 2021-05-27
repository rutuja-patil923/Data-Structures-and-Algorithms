#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;cin>>N;
	int arr[N],sum=0;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
		sum += arr[i];
	}

	// another way is to check if sum till current elements is greater than half of total sum
	int check=0;
	sort(arr,arr+N,greater<int>());

	for (int i = 0; i < N; ++i)
	{
		/* code */
		check += arr[i];
		sum -= arr[i];

		if(check > sum)
		{
			cout<<i+1;
			break;
		}
	}
}