#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1e9 + 7
#define input(arr,N) for(int i=0;i<N;i++) cin>>arr[i]
#define print(arr,N) for(int i=0;i<N;i++) cout<<arr[i]<<" ";
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(N) push_back(N);

struct edge{
	int a,b,w;
};

struct edge arr[100000];
int parent[10001];
bool compare(edge a,edge b)
{
	if(a.w < b.w)
		return true;
	return false;
}
int find(int a)
{
	if(parent[a]==-1)
		return a;
	return parent[a]=find(parent[a]);
}

void merge(int a,int b)
{
	parent[a]=b;
}
void solve()
{
	int n,m,a,b,w;
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		parent[i]=-1;

	for(int i=0;i<m;i++)
	{
		cin>>arr[i].a>>arr[i].b>>arr[i].w;
	}

	sort(arr,arr+m,compare);

	int sum=0;

	for(int i=0;i<m;i++)
	{
		a = find(arr[i].a);
		b = find(arr[i].b);

		if(a!=b)
		{
			sum += arr[i].w;
			merge(a,b);
		}

	}

	cout<<sum;
}
signed main()
{
	fast;
	int t=1;
	//cin>>t;

	while(t--)
	{
		solve();
	}
}
