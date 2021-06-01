// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty Level : Easy
// Input: prices = [7,1,5,3,6,4]
  // 7
  //  \                 6
  //   \         5     / \
  //    \       / \   /   \
  //     \     /   \ /     4
  //      \   /     3
  //       \ / 
  //        1
// Output: 5
// Expected Time complexity : O(N)
// Expected Space Complexity : O(1)

// Question Understanding : Given array has prices for the stocks and we need to select one single day to buy stock and diffrent day to sell the same stock
// Condition being select days for buy and sell such that profit will become maximum

// Approch : to get maximum profit we need to find minimum and maximum prices of stocks.
// Moreover we can't take minimum and maximum directly because it may happen that minimum will come after than maximum.
// hence keeping track of minimum and maximum will work

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[],int n) 
{
    // buy will contain minimum price of stoch till i   
	// profit will contain maximum profit till i
	int buy=INT_MAX,profit=0;
        
    for(int i=0;i<n;i++)
    {
        if(prices[i] < buy)
            buy=prices[i];
        else
            profit=max(prices[i]-buy,profit);
    }
    return profit;
        
}

//main function
int main()
{
 	int n;cin>>n;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	cout<<maxProfit(arr,n);

 	return 0;
}



