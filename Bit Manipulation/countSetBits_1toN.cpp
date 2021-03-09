// Question Link: https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
// Difficulty Level : Medium

// e.g Input: N = 4 output: 5
//For numbers from 1 to 4.
//For 1: 0 0 1 = 1 set bits
//For 2: 0 1 0 = 1 set bits
//For 3: 0 1 1 = 2 set bits
//For 4: 1 0 0 = 1 set bits
//Therefore, the total set bits is 5.

// Expected Time complexity : O(1)
// Expected Space Complexity : O(1)

// Question Understanding : count set bits from 1 to n (inclusive)
// Approch : by obeservation we can see pattern here starting from right to left
// suppose take one variable packet=2 
// observe rightmost consecutively integers contain as single group of size of packet 
// first we have group of 2 at position 0 in every group one bit is set
// packet size then doubles at each position .i.e at position 1 it will become packet*=2 packet=4 half of the packet size are set bits in each group

#include<bits/stdc++.h>
using namespace std;

int countSetBits_1toN(unsigned n)
{
	// group size starts from 2
	int packet = 2;
	
	// easier for calculation
	n+=1;
	
	// contains answer
	int ans=0;
	
	for(int i=0;i<32;i++)
	{
		
		// in each group no of set bits are half of packet
		int setBits=packet/2;
		
		// complete groups
		ans+= (n/packet) * setBits;
		
		// if any group is incomplete we need to count remaining set bits accordingly
		int rem = n % packet;
		
		
		if(rem-setBits>0)
			ans += rem-setBits;
			
		// condition to stop loop
		// consider any example to get idea
		if(n<packet)	
			break;
		
		// packet size doubles each time
		packet*=2;
	}
	
	return ans;
}

//main function
int main()
{
 	unsigned n;
 	cin>>n;
 	
 	cout<<countSetBits_1toN(n);

 	return 0;
}



