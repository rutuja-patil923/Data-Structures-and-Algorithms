// Question Link: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
// Difficulty Level : Medium
//Input:
//1 2 3 
//4 5 6
//7 8 9  
//Output:
//7 4 1 
//8 5 2
//9 6 3
// Expected Time complexity : O(N^2)
// Expected Space Complexity : O(1)

// Question Understanding : we need to rotate matrix clockwise and with 90 degrees

// Approch : this question is similar to finding transpose of matrix. but it's not enough
// After observation it can be seen that every row is reverse of rwo present in transpose.

#include<bits/stdc++.h>
using namespace std;



void rotateMatrix(vector<vector<int>>& matrix,int n)
{
	// first find transpose
	// it can be found by swapping positions where i < j
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i < j)
				swap(matrix[i][j],matrix[j][i]);
		}
	}
	
	// reverse each row after transpose
	for(int i=0;i<n;i++)
		reverse(matrix[i].begin(),matrix[i].end());
}

void print_Matrix(vector<vector<int>>& matrix,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
}

//main function
int main()
{
 	int n;
	cin>>n;
 	vector<vector<int>> matrix;
 	for(int i=0;i<n;i++)
 	{
 		vector<int> row;
		for(int j=0;j<n;j++)
		{
			int x;cin>>x;
			row.push_back(x);	
		}	
		matrix.push_back(row);
	}
	
	rotateMatrix(matrix,n);
	print_Matrix(matrix,n);

 	return 0;
}



