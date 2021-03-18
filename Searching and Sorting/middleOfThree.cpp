// Question Link : https://practice.geeksforgeeks.org/problems/middle-of-three2926/1#

// Calculate middle element by minimum no. of comparisons.

#include<bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C)
{
        // total 3 comparisons needed
        if(A < B)
        {
            if(A<C)
            {
                if(B<C)
                    return B;
                return C;
            }
            return A;
        }
        else
        {
            if(A>C)
            {
                if(B<C)
                    return C;
                return B;
            }
            return A;
        }
    }
int main()
{
	int A,B,C;cin>>A>>B>>C;
	cout<<middleOfThree(A,B,C);
}