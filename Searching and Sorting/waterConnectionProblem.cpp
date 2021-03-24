// Question Link : https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1
// Input:
// n = 9, p = 6
// a[] = {7,5,4,2,9,3}
// b[] = {4,9,6,8,7,1}
// d[] = {98,72,10,22,17,66} 
// Output: 
// 3
// 2 8 22
// 3 1 66
// 5 6 10

// Expected Time Complexity: O(n+p)
// Expected Auxiliary Space: O(n+p)

// Approch : array ahs one house which has only inlet and one house with only outlet.
// we need to find components and then apply dfs to find minimum size of diameter of pipe

//____________________________________________________________________________________________________________

#include<bits/stdc++.h>
using namespace std;


// will store starting point of pipe 
int starting[1000];


// ending point of pipe
int ending[1000];

// edge bewteen starting point and ending point
int edge[1000];

int ans;

int minEdge(int node)
{
	// node which don't have ending point
	if(starting[node]==0)
		return node;

	if(edge[node] < ans)
		ans = edge[node];

    minEdge(starting[node]);
}

vector<vector<int>> waterConnection(int N,int P,int a[],int b[],int d[])
{
	
	vector<vector<int>> res;
	for(int i=0;i<P;i++)
	{
		// starting node will contain info about it's end
		starting[a[i]] = b[i];

		// ending node will contain info about it's start
		ending[b[i]] = a[i];

		// edge will be stored at starting index
		edge[a[i]] = d[i];
	}

	for(int i=1;i<=N;i++)
	{
		if(ending[i]==0 && starting[i])
		{
			ans = INT_MAX;

			// component's end node
			int endingNode=minEdge(i);

			res.push_back({i,endingNode,ans});

		}
	}

	return res;
}

int main()
{
	int N,P;
	cin>>N>>P;
	int a[P];
	int b[P];
	int d[P];
	for(int i=0;i<P;i++) cin>>a[i];
	for(int i=0;i<P;i++) cin>>b[i];
	for(int i=0;i<P;i++) cin>>d[i];

	
	vector<vector<int>> ans = waterConnection(N,P,a,b,d);
}
