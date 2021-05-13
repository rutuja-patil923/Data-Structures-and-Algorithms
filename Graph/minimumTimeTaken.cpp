 // only function
// edges will present dependancies

void toposort(vector<vector<int>>&adj,vector<int>&indegree,int V)
{
	vector<int> dist(V,0);
	queue<int> q;

	for(int i=0;i<V;i++)
	{
		if(indegree[i]==0)
		{
			dist[i]=1;
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int current = q.front();
		q.pop();

		for(int child:adj[current])
		{
			indegree[child]--;
			if(indegree[child]==0)
			{
				dist[child]=dist[current]+1;
				q.push(child);
			}
		}
	}

	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
}
void minimumTimeTaken(int V,vector<vector<int>> &edges)
{

 	// will store indegree for each node
 	vector<int> indegree(V,0);

 	vector<vector<int>> adj(V);

 	for(int i=0;i<edges.size();i++)
 	{
 		int a = edges[i][0];
 		int b = edges[i][1];
 		adj[a].push_back(b);
 		indegree[b]++;
 	}

 	toposort(adj,indegree,V);
}