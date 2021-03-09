// Question Link: https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1
// Difficulty Level : Basic

//Input: A = 10, B = 20
//Output: 4
//Explanation:
//A  = 01010
//B  = 10100
//As we can see, the bits of A that need 
//to be flipped are 01010. If we flip 
//these bits, we get 10100, which is B

// Expected Time complexity : O(logN)
// Expected Space Complexity : O(1)


#include<bits/stdc++.h>
using namespace std;

int bitDifference(unsigned A,unsigned B)
{
	int ans=0;
	
	for(int i=0;i<32;i++)
	{
		int check = 1<<i;
		
		// checking if any of the number has set bit at position i, in other it should be unset so that bit diffrence count will increase.
		if((check & A) ^ (check & B))
			ans++;
	}
	
	return ans;
}

//main function
int main()
{
 	unsigned A,B;
 	cin>>A>>B;
 	
 	cout<<bitDifference(A,B);

 	return 0;
}



