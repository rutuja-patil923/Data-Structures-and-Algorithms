// Question Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// Difficulty Level : Medium
// Input : R = 4, C = 4
//         matrix[][] = {{1, 2, 3, 4},
//                      {5, 6, 7, 8},
//                      {9, 10, 11, 12},
//                      {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// Expected Time complexity : O(N*M)
// Expected Space Complexity : O(N*M)..[for storing elements in spiral order]

// Question Understanding : We need to traverse matrix spirally means from left-right-bottom-top and keep reapeating same cycle until reach at center


#include<bits/stdc++.h>
using namespace std;

void spiralTraversal(vector<vector<int>> &nums)
{
	vector<int> ans;
	
	// leftmost index
	int left = 0;
	
	// rightmost index
	int right = nums[0].size()-1;
	
	// top row index
	int top = 0;
	
	// bottommost row index
	int bottom = nums.size()-1;
	
	while(top <= bottom)
	{
		// traversal of topmost row
		for(int j=left;j<=right;j++)
    		ans.push_back(nums[top][j]);
    	top++;
    		
    	if(left<=right)
    	{
    		// traversal of rightmost column
			for(int i=top;i<=bottom;i++)
    			ans.push_back(nums[i][right]);
    		right--; 
    	}
    		
    	if(top<=bottom)
    	{
    		// traversal of bottommost row
			for(int j=right;j>=left;j--)
    			ans.push_back(nums[bottom][j]);
    		bottom--;	
    	}
    		
    	if(left<=right)
    	{
    		// traversal of leftmost column
			for(int i=bottom;i>=top;i--)
    			ans.push_back(nums[i][left]);
    		left++;
    	}
	}
	
	for(auto it:ans)
		cout<<it<<" ";
	
}

//main function
int main()
{
 	int m,n;cin>>m>>n;
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
	
	spiralTraversal(nums);

 	return 0;
}



