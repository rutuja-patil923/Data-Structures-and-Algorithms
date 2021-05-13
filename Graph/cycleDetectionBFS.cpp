bool bfs(int node,vector<int> adj[],int par)
    {
        queue<int> q;
        q.push(node);
        
        map<int,int> vis;
        vis[node]=par;
        
        while(!q.empty())
        {
            int root = q.front();
            q.pop();
            for(int child:adj[root])
            {
                if(vis.find(child)==vis.end())
                {
                    q.push(child);
                    vis[child]=root;
                }
                else
                {
                    if(child!=vis[root])
                        return true;
                }
            }
        }
        
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    bool ans=false;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(bfs(i,adj,-1))
	                return true;
	        }
	    }
	    return false;
	}