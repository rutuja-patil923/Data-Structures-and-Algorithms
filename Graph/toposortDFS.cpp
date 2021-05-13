void toposort(int node,vector<int> & vis,stack<int> & st)
{
	vis[node]=1;

	for(int child:adj[node])
	{
		if(!vis[child])
			toposort(child,vis,st);
	}

	st.push(node);
}
