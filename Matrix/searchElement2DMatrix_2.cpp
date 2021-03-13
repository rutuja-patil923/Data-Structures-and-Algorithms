// Question Link: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
// Difficulty Level : Medium
// Input: mat[4][4] = { {10, 20, 30, 40},
//                      {15, 25, 35, 45},
//                      {27, 29, 37, 48},
//                      {32, 33, 39, 50}};
//              x = 29
// Output: Found at (2, 1)
// Expected Time complexity : O(log(N+M))
// Expected Space Complexity : O(1)

// Question Understanding : we need to find element in 2D matrix where each row and each column is sorted.
// This question is little bit differnt from leetcode question
// the only differnce is in leetcode question first element in every row is greater than last element of prvious row.

// Naive Approch : Traverse whole matrix and search element T.C-O(N*M)
// Better Approch : As each row is sorted apply binary search on eah row T.C-O(MlogN)
// Optimal Approch : We can start from top right corner and move according to conditions T.C-O(N+M)
 

#include<bits/stdc++.h>
using namespace std;

bool search2D_matrix(vector<vector<int>> &nums,int key)
{
	// rows
	int m = nums.size();
	
	// columns
	int n = nums[0].size();
	
	int i = 0 , j = n - 1;
	
	// start traversing from top right corner
	while( i<m && j>=0)
	{
		if(nums[i][j] == key)
			return true;
		else if(nums[i][j] < key)
			i++;
		else
			j--;
	}
	
	return false;
}

//main function
int main()
{
 	int m,n;cin>>m>>n;
 	int key;cin>>key;
 	vector<vector<int>> nums;
 	
 	for(int i=0;i<m;i++)
 	{
 		vector<int> row;
		for(int j=0;j<n;j++)
		{
			int x;cin>>x;
			row.push_back(x);	
		}	
		nums.push_back(row);
	}
	
	if(search2D_matrix(nums,key))
		cout<<"True";
	else
		cout<<"False";

 	return 0;
}



