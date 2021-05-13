#include<bits/stdc++.h> 
using namespace std;
#define pii pair<int,pair<int,int>>
void prims(vector<vector<pii>> &adj,int N)
{
//	cout<<"entry";
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	vector<int> visited(N,0);

	pq.push({0,{0,-1}});


	while(!pq.empty())
	{
//		cout<<"entry";
		auto it = pq.top();
		pq.pop();
//		cout<<it.first<<" ";
		int node = it.second.first;
//		cout<<node<<" ";
		if(visited[node])
			continue;
		visited[node]=1;

		if(it.second.second!=-1)
			cout<<it.second.first<<" -> "<<it.second.second<<" = "<<it.first<<'\n';
		for(auto p: adj[node])
		{
			int first = p.second.second;
			if(visited[first]) 
				continue;
//			cout<<first<<" ";
			pq.push({p.first,{p.second.second,p.second.first}});
		}
	}


}
//7 8
//0 1 10
//0 3 40
//1 2 10
//2 3 10
//3 4 2
//4 5 3
//5 6 3
//4 6 8
int main()
{
	// N -> no. of nodes
	// M -> no. of edges
	int N,M;
	cin>>N>>M;

	// adjacency list of vector
	vector<vector<pii>> adj(N);

	for(int i=0;i<M;i++)
	{
		int v1,v2,weight;
		cin>>v1>>v2>>weight;

		adj[v1].push_back({weight,{v1,v2}});
		adj[v2].push_back({weight,{v2,v1}});
	}
//	for(int i=0;i<N;i++)
//	{
//		for(auto p:adj[i])
//			cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<" "<<endl;
//		cout<<endl;
//	}
	prims(adj,N);
}
