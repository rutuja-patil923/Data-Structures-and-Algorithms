// Question Link: https://leetcode.com/problems/search-a-2d-matrix/
// Difficulty Level : Medium
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Expected Time complexity : O(log(N+M))
// Expected Space Complexity : O(1)

// Question Understanding : Search element in matrix where conditions are given as follows:
// 1.Integers in each row are sorted from left to right
// 2.The first integer of each row is greater than the last integer of the previous row

// Naive approch : Traverse whole matrix and search element
// Approch 1 : As each row is sorted apply binary search on eah row T.C-O(MlogN)
// Approch 2 : We can start from top right corner and move according to conditions T.C-O(N+M)
// Approch 3 : we can take all elements in extra array and do binary serch T.C-O(log(N+M)) S.C-O(N+M)
// Space complexity in Approch 3 can be reduced with following approch.

#include<bits/stdc++.h>
using namespace std;

bool search2DMatrix(vector<vector<int>> &nums,int key)
{
	// suppose all elements are one array only and then apply binary search without using extra space
	
	// rows
	int m = nums.size();
	
	// columns
	int n = nums[0].size();
	
	int low = 0;
	int high = m*n - 1;
	
	// apply binary search on matrix as if all elements are in array
	while(low<=high)
	{
		int mid = (low+high)/2;
		
		// finding row and column in matrix for middle element
		int row = mid / m;
		int col = mid % n;
		
		if(nums[row][col] == key)
			return true;
		else if(nums[row][col] < key)
			low = mid + 1;
		else
			high = mid - 1;
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
	
	if(search2DMatrix(nums,key))
		cout<<"True";
	else
		cout<<"False";

 	return 0;
}



