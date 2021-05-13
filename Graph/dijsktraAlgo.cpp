#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int vis[100];
vector<pi> adj[100];
int dist[1000];

void Dijsktras(int N)
{
	for(int i=1;i<=N;i++)
		dist[i]=INT_MAX;

	priority_queue<pi,vector<pi>,greater<pi>> pq;
	pq.push({0,1});
	dist[1]=0;

	while(!pq.empty())
	{
		pi tmp = pq.top();
		pq.pop();

		int curr = tmp.second;
		int d = tmp.first;

		for(pi edge:adj[curr])
		{
			if(d + edge.second < dist[edge.first])
			{
				pq.push({d+edge.second,edge.first});
				dist[edge.first]= d + edge.second;
			}
		}
	}

	for(int i=1;i<=N;i++)
		cout<<dist[i]<<" ";
}
int main()
{
	int N,M;
	cin>>N>>M;
	int a,b,w;

	// edges input
	while(M--)
	{
		cin>>a>>b>>w;

		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}

	Dijsktras(N);
}