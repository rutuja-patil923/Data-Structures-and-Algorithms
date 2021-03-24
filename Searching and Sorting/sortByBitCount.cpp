// Question Link : https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#
// Input: 
// arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
// Output:
// 15 7 5 3 9 6 2 4 32
// Explanation:
// The integers in their binary
// representation are:
// 15 - 1111
// 7  - 0111
// 5  - 0101
// 3  - 0011
// 9  - 1001
// 6  - 0110
// 2  - 0010
// 4  - 0100
// 32 - 10000
// hence the non-increasing sorted order is:
// {15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
// Expected Time complexity : O(NlogN)
// Expected space complexity : O(1)

// Note : if no. of bits are same in two numbers then they will appear according to thier positions in array.
// Approch 1 : Insertion Sort | create temprary array which stores count of bits and then apply insertion sort to find correct position of array element O(N^2) O(N)
// Approch 2 : Counting sort | maximum bits can be 32 only.hence create array of 32 and push elements according to no. of total bits in it. O(N) O(N)
// Approch 3 : STL | use of stl functions for sorting. e.g stable_sort,__builtin_count O(NlogN) O(1)
// Approch 4 : Hashing | key as no. of bits and value will be array element and then sort it

//_______________________________________________________________________________________________________________________________

//Approch 1 
#include<bits/stdc++.h>
using namespace std;
int countBits(int X)
{
	int count = 0;
	for(int bit = 0;bit<32;bit++)
	{
		int check = 1<<bit;
		if(check & X)
			count ++;
	}
	return count;
}
void sortByBit(int nums[],int N)
{
	int temp[N];
	for(int i=0;i<N;i++)
		temp[i] = countBits(nums[i]);

	for(int i=1;i<N;i++)
	{
		int bits = temp[i];
		int number = nums[i];

		int j = i - 1;
		while(j >= 0 && bits > temp[j])
		{
			temp[j+1] = temp[j];
			nums[j+1] = nums[j];
			j--;
		}

		temp[j+1] = bits;
		nums[j+1] = number;
	}

	for(int i=0;i<N;i++) cout<<nums[i]<<" ";
}

int main()
{
	int N;
	cin>>N;
	int nums[N];
	for(int i=0;i<N;i++) cin>>nums[i];

	sortByBit(nums,N);
}
