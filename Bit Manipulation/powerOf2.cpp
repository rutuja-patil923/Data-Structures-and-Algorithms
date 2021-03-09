// Question Link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
// Difficulty Level : Easy
// e.g Input: N = 5 output: false
// Expected Time complexity : O(logN)
// Expected Space Complexity : O(1)

// Question Understanding : Find if no is power of 2 bu just checking count of set bits is 1.
// another approch to check if number is power of 2 or not is N & (N-1) is always 0 if number is power of 2

#include<bits/stdc++.h>
using namespace std;

bool setBitPosition(unsigned n)
{
	// count no. of set bits
	int count=0;

	for(int i=0;i<32;i++)
	{
		int check = 1 << i;
		
		if(n & check)
			count++;
	}
	
	
	if(count == 1)
		return true;
	return false;
}

//main function
int main()
{
 	unsigned n;
 	cin>>n;
 	
 	if(setBitPosition(n))
 		cout<<"true";
 	else
 		cout<<"false";
 	return 0;
}




