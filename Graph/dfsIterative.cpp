 void dfs(int root,int V,vector<vector<int>> & adj)
 {
 	stack<int> st;
 	st.push(root);

 	vector<int> visited(V,0);

 	while(!st.empty())
 	{
 		int v = st.top();
 		st.pop();

 		if(visited[v])
 			continue;

 		visited[v]=1;
 		cout<<v<<" ";

 		for(auto it=adj[v].rbegin();it!=adj[v].rend();it++)
 		{
 			if(!visited[*it])
 				st.push(*it);
 		}
 	}
 }