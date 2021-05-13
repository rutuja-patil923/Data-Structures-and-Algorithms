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

void bfs(int root)
{
	//cout<<"Entry in bfs";
	vis[root]=1;
	level[root]=1;

	queue<int> q;
	q.push(root);

	while(!q.empty())
	{
		int current = q.front();q.pop();

		for(int child:adj[current])
		{
			if(!vis[child])
			{
				vis[child]=1;
				level[child]=level[current]+1;
				parent[child]=current;
				q.push(child);
			}
		}
	}
}

int lca(int a,int b)
{
	int d = abs(level[a]-level[b]);

	if(level[b]<level[a])
		swap(a,b);

	while(d>0)
	{
		b = parent[b];
		d--;
	}

	if(a==b) return a;

	while(parent[a]!=parent[b])
	{
		a = parent[a];
		b = parent[b];
	}

	return parent[a];
}
void solve()
{
	int N,M;
	cin>>N>>M;

	// Building graph
	while(M--)
	{
		//cout<<"Entry in while loop";
		int a,b;
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int a,b;cin>>a>>b;
	
	//cout<<"Input done\n";
	// level and parent array formation
	bfs(1);
	
	//cout<<"BFS done!\n";
	
//	for(int i=1;i<=N;i++)
//		cout<<parent[i]<<" ";
//	cout<<"\n";
//	for(int i=1;i<=N;i++)
//		cout<<level[i]<<" ";

	cout<<lca(a,b);

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
