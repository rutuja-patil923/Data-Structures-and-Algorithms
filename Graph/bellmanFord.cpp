#include<bits/stdc++.h>
using namespace std;
struct Edge {
	int start;
	int end;
	int weight;
}
const inf = 1e9 +7;
int main()
{
	int N,M;
	cin>>N>>M;

	vector<Edge> edges(M);

	for(int i=0;i<M;i++)
		cin>>edges[i].start>>edges[i].end>>edges[i].weight;
	int root;
	cin>>root;

	vector<int> dist(N,inf);

	dist[root]=0;

	for(int i=0;i<N-1;i++)
	{
		for(int i=0;i<M;i++)
		{
			if(dist[edges[i].start]<inf)
				dist[edges[i].end] = min(dist[edges[i].end],dist[edges[i].start] + edges[i].weight);
		}
	}

}