
bool isBipartite(int root,int col)
{
	vis[root]=1;
	colour[root]=col;

	for(int child:adj[root])
	{
		if(!vis[child])
		{
			if(isBipartite(child,col^1))
				return true;
		}
		else
		{
			if(colour[child]==colour[root])
				return true;
		}
	}

	return false;
}