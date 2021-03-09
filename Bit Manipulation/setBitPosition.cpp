// Question Link: https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
// Difficulty Level : Medium
// e.g Input: N = 2 output: 2..[0010 at 2nd position bit is set]
// Expected Time complexity : O(logN)
// Expected Space Complexity : O(1)


#include<bits/stdc++.h>
using namespace std;

int setBitPosition(unsigned n)
{
	// count no. of set bits
	int count=0;
	
	// iterator thorugh bits
	int i=0;
	
	// position of set bit
	int pos;
	
	for(int i=0;i<32;i++)
	{
		int check = 1 << i;
		
		if(n & check)
		{
			pos=i+1;
			count++;
		}
	}
	
	
	if(count == 1)
		return pos;
	return -1;
}

//main function
int main()
{
 	unsigned n;
 	cin>>n;
 	
 	cout<<setBitPosition(n);

 	return 0;
}



