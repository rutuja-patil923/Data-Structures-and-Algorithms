// Question Link: https://practice.geeksforgeeks.org/problems/count-squares3649/1#
// Difficulty Level : Basic
// Input : N = 9 Output: 2
// Expected Time complexity : O(sqrt(N))
// Expected Space Complexity : O(1)

// Question Understanding : We need to find no. of perfect squares less than N


#include<bits/stdc++.h>
using namespace std;

int countSquares(int N) 
{
        int ans=0;
        
        for(int i=1;i*i<N;i++)
            ans++;
            
        return ans;
}

//main function
int main()
{
 	int n;cin>>n;
 	
 	cout<<countSquares(n);

 	return 0;
}



