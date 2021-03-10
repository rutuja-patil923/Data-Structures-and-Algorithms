// Question Link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
// Difficulty Level : Medium

//Input: n = 5
//Output: 25

// Expected Time complexity : O(logN)
// Expected Space Complexity : O(1)

// Question Understanding : Given an integer n, calculate the square of a number without using *, / and pow(). 

// Naive Approch : we can find square by just adding that number same number of times. T.C-O(N)
// Optimal Approch 1 : if n is even square (n) = 4 * square(n/2) if n is odd square(n) = 4 * square(floor(n/2)) + 4 * floor(n/2) +1
// why ? if n%2 == 0 i.e if it is even n = 2 * n/2 Hence n ^ 2 = 4 * square(n/2) 
// if n%2 == 1 i.e if it is odd n = 2*((n -1 + 1)/2) Hence n ^ 2 = 4 * ((n - 1 + 1) ^ 2)/4 = 4 * square(floor(n/2)) + 4 * floor(n/2) +1
 
// Optimal Approch 2 : e.g binary representaion of 6 is 0110 6 * 6 = 6 * ( 2^0 + 2^2 + 2^1 + 2^0 ) we can multiply with left shift operator
// below is implementation of approch 2
#include<bits/stdc++.h>
using namespace std;

void squareBit(unsigned n)
{
	// stores ans 
	int ans=0;
	
	for(int bit = 0; bit<32 ; bit++)
	{
		int check = 1<<bit;
		
		// checking if bit is set or not
		if(check & n)
			ans += (n<<bit);
	}
	
	cout<<ans;
}

//main function
int main()
{
 	unsigned n;
 	cin>>n;
 	
 	squareBit(n);

 	return 0;
}



