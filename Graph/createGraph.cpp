#include<bits/stdc++.h>
using namespace std;

int vis[100];
vector<int> adj[100];

void dfs(int node)
{
	vis[node]=1;
	cout<<node<<" ";

	for(int child:adj[node])
	{
		if(!vis[child])
			dfs(child);
	}
}
int main()
{
	int N,M;
	cout<<"Enter no. of nodes->";cin>>N;
	cout<<"Enter no. of edges->";cin>>M;

	int a,b;

	// edges input
	while(M--)
	{
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
}