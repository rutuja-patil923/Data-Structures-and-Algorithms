// Question Link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
// Difficulty Level : Medium
// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Expected Time complexity : O(RlogC)..[where R = rows,C = columns]
// Expected Space Complexity : O(1)

// Question understanding : We need to find row in matrix which contains maximum no. of 1's
// Naive Approch : We can traverse whole matrix and count no of 1's in each and updating maximum count each time T.C-O(R*C)
// Better Approch : as rows are sorted binary search can be applied to each row to find lower bound of 1 i.e first occurrence of 1
// Optimal Approch : T.C-O(R+C) discussed separately

#include<bits/stdc++.h>
using namespace std;

int maximum1Row(vector<vector<int>> &nums)
{
	// rows
	int R = nums.size();
	// columns
	int C = nums[0].size();

	// contains index of row which contains maximum no. of 1's
	// initilize as if occurrence in last column
	int ans = C-1,max_row;
	for(int i=0;i<R;i++)
	{
		// lower_bound is STL function which will give first occurrence of 1
		int lowerBound = lower_bound(nums[i].begin(),nums[i].end(),1)-nums[i].begin();

		// if column no. is less means 1 has occurred earlier and hence more no. of 1's
		if(lowerBound < ans)
		{
			ans = lowerBound;
			max_row = i;
		}
	}

	return max_row;

}

//main function
int main()
{
 	int R,C;cin>>R>>C;
 	vector<vector<int>> nums;

 	for(int i=0;i<R;i++)
 	{
 		vector<int> row;
 		for(int j=0;j<C;j++)
 		{	
		 	int x;cin>>x;
 			row.push_back(x);
 		}
 		nums.push_back(row);
 	}

 	cout<<maximum1Row(nums);

 	return 0;
}



