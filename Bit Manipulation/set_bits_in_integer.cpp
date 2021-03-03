// Question Link: https://practice.geeksforgeeks.org/problems/set-bits0143/1
// Difficulty Level : Basic
// e.g Input: 6 output: 2
// Time complexity : O(logN)..each time no. is getting half
// Space Complexity : O(1) 


// Approch each time will calculate AND with 1 and  right shift N with 1 so basically right shift by one means N=N/2
// For example N=6 Binary reprensentation will be 0110 and 1's binary representation is 0001 
// 0110 & 0001 count=0 right shift=0011
// 0011 & 0001 count=1 right shift=0001
// 0001 & 0001 count=1 right shift=0000
// end of loop

#include<bits/stdc++.h>
using namespace std;

int set_bits(int n)
{
	int count=0;
	
	while(n)
	{
		if(n&1)
			count++;
		
		//right shift
		n>>=1;	
	}
	
	return count;
} 

//main function
int main()
{
 	int n;cin>>n;
 	
 	cout<<"No. of set bits are "<<set_bits(n);
 	return 0;
}


