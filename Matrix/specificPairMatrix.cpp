// Question Link: https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
// Difficulty Level : Hard
// Input:
// mat[N][N] = {{ 1, 2, -1, -4, -20 },
//             { -8, -3, 4, 2, 1 }, 
//             { 3, 8, 6, 1, 3 },
//             { -4, -1, 1, 7, -6 },
//             { 0, -4, 10, -5, 1 }};
// Output: 18
// Expected Time complexity : O(N*M)
// Expected Space Complexity : O(N*M)

// Question Understanding : we need to find pair matrix[c][d] and matrix[a][b] such that differnce between them is maximum and c > a & d > b

// Naive Approch : we can take one element at a time and then search again maximum element in remaining matrix and keep updating max value difference T.C-O(N^4)
// Better Approch : create maximum matrix which will contain maximum at position i and j considering matrix from right bottom corner.
// keep checking if difference will become maximum


#include<bits/stdc++.h>
using namespace std;

void specificPair(vector<vector<int>> &nums)
{
	// will store maximum difference between pairs
	int ans=INT_MIN;
	
	// no. of rows
	int m = nums.size();
	
	// no. of columns
	int n = nums[0].size();
	
	// maximum matrix which will contain maximum till i and j from bottommost right corner
	int maxArr[m][n];
	
	// initialize bottom row of max matrix
	int maxi = nums[m-1][n-1];
	
	for(int j = n-1;j>=0;j--)
	{
		maxi = max(maxi,nums[m-1][j]);
		maxArr[m-1][j] = maxi;
	}
	
	// initlize last column of matrix
	maxi = nums[m-1][n-1];
	for(int i=m-2;i>=0;i--)
	{
		maxi = max(maxi,nums[i][n-1]);
		maxArr[i][n-1] = maxi;
	}
	
	// start traversing upwards now in matrix
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			// will store maximum difference
			ans = max(ans,maxArr[i+1][j+1]-nums[i][j]);
			
			// will store maximum element until that portion
			maxArr[i][j] = max(nums[i][j],max(maxArr[i+1][j],maxArr[i][j+1])); 
		}
	}
	
	cout<<ans;
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
	
	specificPair(nums);

 	return 0;
}



