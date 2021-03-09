// Question Link: https://www.geeksforgeeks.org/copy-set-bits-in-a-range/
// Difficulty Level : Medium
// e.g Input: x = 10, y = 13, l = 2, r = 3 output: Modified x is 14
// Expected Time complexity : O(1)
// Expected Space Complexity : O(1)

// Question Understanding : x has binary representation 1010 and y has 1101 now in the range 2 to 3 at 3rd position y's bit is set will copy to x
// x will become 1110 which will give output 14

// Approch 1 : we can traverse from l to r bits and check if y's bit is set or not by doing AND with 1 
// Approch 2 : we can use whole range mask to do task only once.No traversing

#include<bits/stdc++.h>
using namespace std;

void copySetBits(unsigned x,unsigned y,unsigned l,unsigned r)
{
	// we're creating mask of r-l+1 length
	// suppose l=2,r=3 length will be 3-2+1=2
	// mask will be 0011
	int mask = (1<<(l-r+1))-1;
	
	// now moving mask at it's correct position
	// 0011 << 1 = 0110
	mask = mask << (l-1);
	
	// checking with y if it has set bits in that range if yes doing OR with X
	x = x | (mask & y); 
}

//main function
int main()
{
 	// unsigned data type is used for only +ve integers
 	// signed data type is used for 0, -ve , +ve integers
 	unsigned x,y,l,r;
 	cin>>x>>y>>l>>r;
 	
 	copySetBits(x,y,l,r);

 	return 0;
}



