// Question Link: https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
// Difficulty Level : Medium
// Input : a = 10, b = 3 Output : 3
// Expected Time complexity : O(log a)
// Expected Space Complexity : O(1)

// Question Understanding : division of two integers with using '/' and '%' operator

// Naive Approch : keep repeating substraction of divisior until remainder is less than divisor and add each time when substracting and find quotient T.C-O(dividend)
// Optimal approch : Using bit manipulation
// instead of subtracting divisor only one time we can do that with power of 2 dividend - quotient * divisor 

#include<bits/stdc++.h>
using namespace std;

void divideBit(long long  dividend,long long divisor)
{
	// final ans. sign will be negative only when one of theem is negative otherwise it'll be positive only
	int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
	
	long long result=0,quotient=0;
	
	for(int i=31;i>=0;i--)
	{
		// checking if it's possible to 2's power when multiplying with divisor it contributes in quotient
		if(result + (divisor<<i) <= dividend)
		{
			result += divisor<<i;
			
			quotient |= (1LL<<i);
		}
	}
	
	cout<<sign*quotient;
	
}

//main function
int main()
{
 	int a,b;
 	cin>>a>>b;
 	
 	divideBit(a,b);

 	return 0;
}



