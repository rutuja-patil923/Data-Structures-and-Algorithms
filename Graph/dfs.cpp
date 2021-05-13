#include<bits/stdc++.h>
using namespace std;

int vis[100];
vector<int> adj[100];

void dfs1(int node)
{
	vis[node]=1;
	cout<<node<<" ";

	for(int child:adj[node])
	{
		if(!vis[child])
			dfs1(child);
	}
}

// My approch complexity is high
// void dfs2(int root)
// {
// 	memset(vis,0,sizeof(vis));
// 	stack<int> st;
// 	st.push(root);
// 	vis[root]=1;
// 	vector<int> res; 
// 	res.push_back(root);

// 	while(!st.empty())
// 	{
// 		int curr = st.top(),flag=0;
// 		for(int child:adj[curr])
// 		{
// 			if(!vis[child])
// 			{
// 				res.push_back(child);
// 				st.push(child);
// 				vis[child]=1;
// 				flag=1;
// 				break;
// 			}
// 		}
// 		if(!flag)
// 			st.pop();
// 	}
// 	cout<<'\n';
// 	for(int i:res)
// 		cout<<i<<" ";
// }
//7 7
//1 2
//2 3
//2 5
//1 3 
//3 6
//3 7
//6 7
// void toposort(int node,stack<int> & st)
// {
// 	vis[node]=1;

// 	for(int child:adj[node])
// 	{
// 		if(!vis[child])
// 			toposort(child,st);
// 	}

// 	st.push(node);
// }
// void print(stack<int> &st)
// {
// 	while(!st.empty())
// 	{
// 		cout<<st.top()<<" ";
// 		st.pop();
// 	}
// }
int main()
{
	int N,M;
	//cout<<"Enter no. of nodes->";
	cin>>N;
	//cout<<"Enter no. of edges->";
	cin>>M;

	int a,b;

	// edges input
	while(M--)
	{
		cin>>a>>b;

		adj[a].push_back(b);
		//adj[b].push_back(a);
	}

	//dfs1(0);

	stack<int> st;
	for(int i=0;i<N;i++)
	{
		if(!vis[i])
			toposort(i,st);
	}
	print(st);
	// dfs2(0);
}
