#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void countNoOfWords(vector<vector<char>>arr,int N,string check,int index,int x,int y)
{
	if(index==check.length())
	{
		//cout<<"Adding for "<<x<<" "<<y<<endl;
		cnt++;
		return;
	}
	if(x<0 || y<0 || x>=N || y>=N || arr[x][y]!=check[index])
		return;
	char ch = arr[x][y];
	arr[x][y]='*';
	countNoOfWords(arr,N,check,index+1,x-1,y);
	countNoOfWords(arr,N,check,index+1,x,y+1);
	countNoOfWords(arr,N,check,index+1,x+1,y);
	countNoOfWords(arr,N,check,index+1,x,y-1);
	arr[x][y]=ch;
}
int main()
{
	// size of 2D grid dimensions
	int N;
	cin>>N;

	// 2D grid
	vector<vector<char>> arr(N,vector<char>(N));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cin>>arr[i][j];
	}

	string check;
	cin>>check;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]==check[0])
			{
				//cout<<"entry for "<<i<<" "<<j<<endl;
				countNoOfWords(arr,N,check,0,i,j);
			}
		}
	}
	
	cout<<cnt/4;
}