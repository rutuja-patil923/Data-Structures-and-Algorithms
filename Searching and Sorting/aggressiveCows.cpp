#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int N,C;cin>>N>>C;
	int arr[N];

	for(int i=0;i<N;i++)
		cin>>arr[i];

	sort(arr,arr+N);

	// range will be in between 1 to if suppose there are only 2 cows then if we place them on extreme positions max distance will be arr[N-1]-arr[0]
	int low=1,high=arr[N-1]-arr[0],res;

	while(low<=high)
	{
		// every time we're eliminating half of range
		int mid = (low+high)/2;
		int count=C-1;
		int prev=arr[0];

		for(int i=1;i<N;i++)
		{
			if(arr[i]-prev>=mid)
			{
				count--;
				prev=arr[i];
			}
			if(!count)
				break;
		}

		if(count==0)
		{
			res = mid;
			low = mid+1;
		}
		else
			high = mid-1;
	}
	cout<<res<<'\n';

}
int main()
{
	int t;
	cin>>t;

	while(t--)
		solve();
}