#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	sort(arr,arr+N);
	vector<int> res;

	for(int i=0;i<N/2;i++)
	{
		res.push_back(arr[i]);
		res.push_back(arr[N-1-i]);
	}
	
	if(N%2)
		res.push_back(arr[N/2+1]);
//	for(int i=0;i<N;i++)
//		cout<<res[i]<<" ";
	int ans=abs(res[N-1]-res[0]);
	//cout<<endl<<ans<<endl;
	for(int i=1;i<N;i++)
		ans += abs(res[i]-res[i-1]);

	cout<<ans;

}
