// Question Link: https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/
// Difficulty Level : Hard
// Input: mat[4][5] = { {1, 2, 3, 4, 5},
//                    {2, 4, 5, 8, 10},
//                    {3, 5, 7, 9, 11},
//                    {1, 3, 5, 7, 9},
//                  };
// Output: 5
// Expected Time complexity : O(N*M)
// Expected Space Complexity : O(N)

// Suppose N = no. columns
//         M = no. of rows

// Question Understanding : We need to find elements which are common in all rows condition here is all elemnts in each row are sorted

// Approch : Use of merge sorting technique
// create array of size of no. rows which will store in each row currently at which column we're traversing
// now store minimum element column no. in corresponding row
// suppose row = 3 contains minimum element in 4 th column then row[3]=4 and will traverse in remaining rows to find column no. of that minimum element 
// keep iterating through other rows until you find that minimum no.


#include<bits/stdc++.h>
using namespace std;

int commonElementRows(vector<vector<int>> & nums)
{
	// no. of columns
	int n = nums[0].size();
	
	// no. of rows
	int m = nums.size();
	
	// each i'th element will contain column no. we're currently for i'th row
	int col[m];
	// initilize all columns as last column as we're starting from last
	// as traversing from last find minimum element
	// why ? because anyways higher elements can't be found as minimum element is last element in that particular row
	for(int i=0;i<m;i++)
		col[i] = n-1;
		
	// let us suppose first row contains minimum element
	int min_row = 0;
	
	// loop will traverse until we go upto first colum from right to left
	while(col[min_row] >= 0)
	{
		// finding min element row
		for(int i=0;i<m;i++)
		{
			if(nums[i][col[i]] < nums[min_row][col[min_row]])
				min_row = i;
		}
		
		int count=0;
		
		for(int i=0;i<m;i++)
		{
			// it means that in i'th row at whereever column it is if it is greater than min_row'th row and it's column
			// e.g suppose we have min_row = 3 and col[min_row]= 4
			// it means at 4'th column and 3'rd row we have current minimum element
			// now check if any row contains greater than this min element then decrease it's column
			// i.e move left
			if(nums[i][col[i]]>nums[min_row][col[min_row]])
			{
				// means we have reached to first column
				if(col[i]==0)
					return -1;
				else
					col[i] -= 1; // moving left
			}
			else
				count++;
		}
		
		if(count==m)
			return nums[min_row][col[min_row]];
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
	
	cout<<"Common Element is "<<commonElementRows(nums);
 	return 0;
}




