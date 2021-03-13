// Question Link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
// Difficulty Level : Basic
//Input:
//N=4
//Mat=[[10,20,30,40],
//[15,25,35,45] 
//[27,29,37,48] 
//[32,33,39,50]]
//Output:
//10 15 20 25 
//27 29 30 32
//33 35 37 39
//40 45 48 50
// Expected Time complexity : O(N^2log(N))
// Expected Space Complexity : O(N^2)

// Question Understanding : sort elements in matrix and print them all

// Approch : Store all elements in temprary array and sort that array


#include<bits/stdc++.h>
using namespace std;

void printSorted(vector<vector<int>> &nums)
{
	int n = nums.size();
	
	int temp[n*n];
	
	int k = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			temp[k++]=nums[i][j];
		}
	}
	
	sort(temp,temp+ n*n);
	
	for(int i=0;i<n*n;i++)
		cout<<temp[i]<<" ";
}

//main function
int main()
{
 	int n;cin>>n;
 	
 	vector<vector<int>> nums;
 	
 	for(int i=0;i<n;i++)
 	{
 		vector<int> row;
		for(int j=0;j<n;j++)
		{
			int x;cin>>x;
			row.push_back(x);	
		}	
		nums.push_back(row);
	}
	
	printSorted(nums);

 	return 0;
}



