#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1e9 + 7
#define vi vector<int>
#define input(arr,N) for(int i=0;i<N;i++) cin>>arr[i]
#define print(arr,N) for(int i=0;i<N;i++) cout<<arr[i]<<" ";
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(N) push_back(N);


vi adj[1000];
int vis[1000],level[1000],parent[1000];
int LCA[100][100];
// it should be LCA[N+1][MAXN]
// N = no. of nodes
// MaxN = max 2's power 2^i <= N -> i <= log2(N)=MAXN

// *************************** Preprocessing ***********************************
void dfs(int node,int par,int d)
{
	// d indicates level
	vis[node]=1;
	LCA[node][0]=par;
	level[node]=d;

	for(int child : adj[node])
	{
		if(!vis[child])
			dfs(child,node,d+1);
	} 
}
void init(int N)
{
	memset(LCA,-1,sizeof(LCA));
	memset(level,0,sizeof(level));
	memset(vis,0,sizeof(vis));
	dfs(1,-1,1);
	int MaxN = log2(N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=MaxN;j++)
		{
			int parent = LCA[i][j-1];
			if(parent!=-1)
				LCA[i][j]=LCA[parent][j-1]; 
		}
	}
}

//*******************************  Algorithm ******************************
int lca(int a,int b,int N)
{
	int d = abs(level[a]-level[b]);

	if(level[b]<level[a])
		swap(a,b);
	int MaxN = log2(N);

	while(d>0)
	{
		int i = log2(d);
		b = LCA[b][i];
		d-= (1<<i);
	}

	if(a==b) return a;


	// still in worst case this while loop run for n times
	// while(parent[a]!=parent[b])
	// {
	// 	a = parent[a];
	// 	b = parent[b];
	// }

	// better alternative
	for(int i=MaxN;i>=0;i--)
	{
		if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i])
		{
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}

	return LCA[a][0];
}
void solve()
{
	int N,M;
	cin>>N>>M;

	// Building graph
	while(M--)
	{
		
		int a,b;
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int a,b;cin>>a>>b;
	init(N);
	
	cout<<lca(a,b,N);

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
