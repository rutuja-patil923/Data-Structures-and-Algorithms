#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> ans;
bool check(int i,int j,vector<vector<int>> &board,int N)
{
	// column check
	for(int row=0;row<N;row++)
	{
		if(board[row][j])
			return false;
	}	

	// diagonal 1 check
	for(int row=i,col=j;row>=0 && col<N; row--,col++)
	{
		if(board[row][col])
			return false;
	}

	// diagonal 2 check
	for(int row=i,col=j;row>=0 && col>=0 ;row--,col--)
	{
		if(board[row][col])
			return false;
	}

	return true;
}
bool NQueens(vector<vector<int>> board,int row,int N,vector<pair<int,int>> p)
{
	if(row == N)
	{
		ans.push_back(p);
		return true;
	}

	for(int col=0;col<N;col++)
	{
		vector<pair<int,int>> copy = p;
		if(check(row,col,board,N))
		{
			board[row][col]=1;
			copy.push_back({row,col});
			if(NQueens(board,row+1,N,copy))
				return true;
			board[row][col]=0;
		}
	}
	return false;
}
int main()
{
	// board size
	int N;
	cin>>N;

	vector<vector<int>> board(N,vector<int>(N,0));
	vector<pair<int,int>> p;

	NQueens(board,0,N,p);

	for(int i=0;i<ans.size();i++)
	{
		for(auto it:ans[i])
			cout<<it.first<<" "<<it.second<<"->";
		cout<<endl;
	}
}
