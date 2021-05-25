// Codechef May Cook-Off 2021
// Question Link : https://www.codechef.com/COOK129C/problems/CSUBS 

// Question is calculate minimum no of modifications in array so that subarray of k length will have same sum

// Every k'th position should be same 
// suppose array of length 8 and K = 3
// index ->              0 1 2 3 4 5 6 7
// same array element -> 0 1 2 0 1 2 0 1
// hence will calculate frequency of elements at k'th index
// consider at every 0th index 3 elements having value 2 and 5 elements are having value 6 
// so it'll be beneficial if we change 3 elements into 6

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1e9 + 7
#define vi vector<int>
#define pi pair<int,int>
#define input(arr,N) for(int i=0;i<N;i++) cin>>arr[i]
#define print(arr,N) for(int i=0;i<N;i++) cout<<arr[i]<<" ";
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(N) push_back(N);


void solve()
{
	int N,K;
	cin>>N>>K; 

	// here array of map
	map<int,int> mp[K];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		mp[i%K][arr[i]]++;
	}

	int ans=0;

	for(int i=0;i<K;i++)
	{
		int mx = -1,tot=0;
		for(auto [num,cnt]:mp[i])
		{
			tot += cnt;
			mx = max(mx,cnt);
		}

		ans += (tot - mx);
	}
	
	cout<<ans<<'\n';
}

signed main()
{
	fast;
	int t=1;
	cin>>t;
	while(t--)
		solve();
}
