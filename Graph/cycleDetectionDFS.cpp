bool dfs(int node,vector<int>&vis,vector<int>adj[],int par)
    {
        vis[node]=1;
        for(int child:adj[node])
        {
            // can't directly return because it'll find cycle if present 
            // suppose adjacency list for some node is like this 1->2->3->4->6
            // first it wll call 2 and then cycle continues
            // but if cycle present on 3 it'll never find as it already eturning false
            if(!vis[child])
            {
                if(dfs(child,vis,adj,node))
                    return true;   
            }    
            else
            {
                if(child!=par)
                    return true;
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
	            if(dfs(i,vis,adj,-1))
    	            return true;
	        }
	    }
	    return false;
	}