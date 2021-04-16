#include<bits/stdc++.h>
using namespace std;

int vis[1000];
vector<int> adj[1000];
int parent[1000];

bool dfs(int node)
{
	vis[node]=1;

	for(auto child:adj[node])
	{
		if(!vis[child])
			dfs(child);
		else if(child!=parent[node])
			return false;
	}
	return true;
}

int main()
{
	int edges;cin>>edges;

	while(edges--)
	{
		int start,end;
		cin>>start>>end;
		parent[end]=start;

		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	if(dfs(0))
		cout<<"Graph is Tree";
	else
		cout<<"Graph is not Tree";
}