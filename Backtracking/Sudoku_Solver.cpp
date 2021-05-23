#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>> & board,int i,int j,char ch)
{
	// row check
	for(int col=0;col<9;col++)
	{
		if(board[i][col]==ch)
			return false;
	}

	// column check
	for(int row=0;row<9;row++)
	{
		if(board[row][j]==ch)
			return false;
	}

	int row=i-i%3,col=j-j%3;

	// 3*3 matrix check
	for(int x=0;x<3;x++)
	{
		for(int y=0;y<3;y++)
		{
			if(board[row+x][col+y]==ch)
				return false;
		}
	}

	return true;
}
bool sudokuSolver(vector<vector<char>> & board,int i,int j)
{
	if(i==9)
		return true;
	if(j==9)
		return sudokuSolver(board,i+1,0);
	if(board[i][j]!='.')
		return sudokuSolver(board.i,j+1);

	for(char ch='1';ch<='9';ch++)
	{
		if(check(board,i,j,ch))
		{
			board[i][j]=ch;
			if(sudokuSolver(board,i,j+1))
				return true;
			board[i][j]='.';
		}
	}

	return false;
}
int main()
{
	vector<vector<char>> board(9,vector<char>(9));

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cin>>board[i][j];
	}

	sudokuSolver(board,0,0);
}