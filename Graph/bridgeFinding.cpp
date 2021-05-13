#include<bits/stdc++.h>
using namespace std;
int timer=0;
void bridges(int root,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<int>&in,vector<int>&low)
{
	vis[root]=1;
	in[root]=low[root]=timer++;

	for(int child:adj[root])
	{
		if(child==parent)
			continue;
		// forward edge
		// which can only be eligible to become bridge 
		if(!vis[child])
		{
			bridges(child,root,vis,adj,in,low);
			low[root] = min(low[child],low[root]);
			if(low[child]>in[root])
				cout<<"Bridge from "<<root<<" "<<child<<endl;
		}
		// backward edge
		else
			low[root]=min(in[child],low[root]);
	}
}
int main()
{
	int N,M;
	cin>>N>>M;

	vector<int> vis(N,0);
	vector<vector<int>> adj(N);
	vector<int> in(N),low(N);

	while(M--)
	{
		int a,b;
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bridges(0,-1,vis,adj,in,low);
}
