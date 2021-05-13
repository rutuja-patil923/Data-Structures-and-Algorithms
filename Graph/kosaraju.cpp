#include<bits/stdc++.h>
using namespace std;
void dfs(int root,vector<int> &vis,vector<vector<int>>&adj,vector<int>&order)
{
	vis[root]=1;

	for(int child:adj[root])
	{
		if(!vis[child])
			dfs(child,vis,adj,order);
	}

	order.push_back(root);
}
void dfs1(int root,vector<vector<int>>&transpose,vector<int>&vis,vector<int>&SCC)
{
	vis[root]=1;

	for(int child:transpose[root])
	{
		if(!vis[child])
			dfs1(child,transpose,vis,SCC);
	}
	SCC.push_back(root);
}
int main()
{
	int N,M;
	cin>>N>>M;

	vector<vector<int>> adj(N),transpose(N);
	vector<int> vis(N,0);

	while(M--)
	{
		int a,b;
		cin>>a>>b;

		adj[a].push_back(b);
		transpose[b].push_back(a);
	}

	vector<int> order;

	for(int i=0;i<N;i++)
	{
		if(!vis[i])
			dfs(i,vis,adj,order);
	}

	fill(vis.begin(), vis.end(),0);

	for(int i=0;i<N;i++)
	{
		if(!vis[order[N-i-1]])
		{
			vector<int> SCC;
			dfs1(order[N-i-1],transpose,vis,SCC);
			for(auto i:SCC)
				cout<<i<<" ";
			cout<<'\n';
		}
	}



}
