#include<bits/stdc++.h>
using namespace std;

int vis[100];
vector<int> adj[100];

void bfs(int node)
{
	vis[node]=1;
	queue <int> q;
	q.push(node);

	while(!q.empty())
	{
		int curr = q.front();
		cout<<curr<<" ";
		q.pop();

		for(int child : adj[curr])
		{
			if(!vis[child])
			{
				vis[child]=1;
				q.push(child);
			}
		}
	} 
}
int main()
{
	int N,M;
	cin>>N>>M;
	int a,b;

	// edges input
	while(M--)
	{
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(1);
}