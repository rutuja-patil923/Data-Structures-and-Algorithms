// Question Link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
// Difficulty Level : Medium
// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Expected Time complexity : O(R + C)..[where R = rows,C = columns]
// Expected Space Complexity : O(1)

// Question understanding : We need to find row in matrix which contains maximum no. of 1's

// This is optimal approch of O(R*log(C)).

#include<bits/stdc++.h>
using namespace std;

int maximum1Row(vector<vector<int>> &nums)
{
	// rows
	int R = nums.size();
	// columns
	int C = nums[0].size();

	// Traversal will start from top left
	int j = C - 1;

	int i = 0;

	int max_row , ans = C - 1;

	while ( j >= 0 && i < R)
	{
		// if element is 1 will move towards left
		if(nums[i][j] == 1)
		{
			j--;
			
			// if reaches at first column
			// means all elements in i'th row are 1
			if(j == -1)
			{
				max_row = i;
				break;
			}
		}
		
		// if 0 found then move bottom	
		else
		{
			// if column no. of is greater
			// e.g in previous row 1's first occurrence at 3rd column and now it's 2nd column
			if (ans > j+1)
			{
				max_row = i;
				ans = j+1;
			}
			i++;
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



