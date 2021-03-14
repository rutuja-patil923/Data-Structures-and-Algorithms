// Question Link: https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
// Difficulty Level : Hard
// Input : 1 3 5
//         2 6 9
//         3 6 9
// Output : Median is 5
// Expected Time complexity : O(32 * R * log(C))
// Expected Space Complexity : O(1)

// Question Understanding : We need to find median of matrix where every row is sorted

// Naive Approch : take all elements in temporary array and sort it and then find median T.C-O(R*Clog(R*C)) S.C-O(R*C)
// Better Approch : as elements in each row are sorted binary search can be used
// find minimum and maximum of matrix 
// minimum can be found by comparing first column elements
// maximum can be found by comparing last column of elements
// apply binary search in between range of maximum and minimum 
// as maximum element can be 2^32 binary search will take log2(2^32)=32

#include<bits/stdc++.h>
using namespace std;

void medianSortedMatrix(vector<vector<int>> &nums)
{
	// rows
	int R = nums.size();

	// columns
	int C = nums[0].size();

	// finding minimum
	int mini = INT_MAX;
	for(int i=0;i<R;i++)
		mini = min(mini,nums[i][0]);

	// findind maximum 
	int maxi = INT_MIN;
	for(int i=0;i<R;i++)
		maxi = max(maxi,nums[i][C-1]);

	// no. of elements should be less than or equal to median
	int lessElements = (R*C+1)/2;

	while(mini <= maxi)
	{
		// to avoid overflow
		int mid = mini + (maxi-mini)/2;

		int count = 0;

		// no.f elements less than or equal to mid
		for(int i=0;i<R;i++)
			count += upper_bound(nums[i].begin(),nums[i].end(),mid)-nums[i].begin();

		// ultimately loop will run until median = mid
		if(count < lessElements)
			mini = mid + 1;
		else
			maxi = mid;
	}

	cout<<mini;
}

//main function
int main()
{
 	int R,C;cin>>R>>C;
 	vector <vector<int>> nums;

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

 	medianSortedMatrix(nums);
 	return 0;
}



