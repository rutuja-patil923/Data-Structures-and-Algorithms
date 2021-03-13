// Question Link: https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
// Difficulty Level : Medium
// Input: mat[4][5] = { {1, 2, 3, 4, 5},
//                    {2, 4, 5, 8, 10},
//                    {3, 5, 7, 9, 11},
//                    {1, 3, 5, 7, 9},
//                  };
// Output: 5
// Expected Time complexity : O(N*M)
// Expected Space Complexity : O(N)..[considering N are no. of columns]

// Suppose N = no. columns
//         M = no. of rows

// Question Understanding : We need to find elements which are common in all rows

// Naive Approch : Take first row elements one by one and search it in matrix T.C-O(M*N*M) S.C-O(1)
// Better Approch : sort elements in each array and then find common elements discussed in separate question. refer in commonElementsSorted.cpp T.C-O(M*N*logN)
// Optimal Approch : Store first row elements and find in each row if that element occurs before increase it's count T.C-O(N*M) S.C-O(N)

#include<bits/stdc++.h>
using namespace std;

void commonElementRows(vector<vector<int>> & nums)
{
	// no. of columns
	int n = nums[0].size();
	
	// no. of rows
	int m = nums.size();
	
	// storing frequency of first row
	unordered_map <int,int> up;
	for(int j=0;j<n;j++)
		up[nums[0][j]] = 1;
		
	// finding comon elements in remaining rows
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			// if elements occurs in each row until i th row
			if(up[nums[i][j]] == i)
				up[nums[i][j]]++;
		}
	}
	
	// elements qualifying given condition
	for(auto it: up)
	{
		// occcurrence is exactly m rows
		if(it.second == m)
			cout<<it.first<<" ";
	}
		
}


//main function
int main()
{
 	int n,m;cin>>n>>m;
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
	
	commonElementRows(nums);
 	return 0;
}



