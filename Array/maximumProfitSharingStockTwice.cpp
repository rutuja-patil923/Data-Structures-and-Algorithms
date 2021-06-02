// Input:   price[] = {10, 22, 5, 75, 65, 80}
//                     10  10  5      5   5
//                     10  22  5   75  65  80
// Output:  87
// Trader earns 87 as sum of 12, 75 
// Buy at 10, sell at 22, 
// Buy at 5 and sell at 80

// Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
// Output:  100
// Trader earns 100 as sum of 28 and 72
// Buy at price 2, sell at 30, buy at 8 and sell at 80

// Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
// Output:  72
// Buy at price 8 and sell at 80.

// Input:   price[] = {90, 80, 70, 60, 50}
// Output:  0
// Not possible to earn.



// This logic can only be applied if there is exactly two minima's are present

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tests;cin>>tests;

	while(tests--)
	{
		int N;cin>>N;
		// valley-peak approch
	    //                    80
	    //                    /
	    //     30            /
	    //    /  \          25       8 -> 80 = 8 -> 25 + 25 -> 80
	    //   /    15       /
	    //  /      \      /
	    // 2        10   /
	    //            \ /
	    //             8
		
		int arr[N];
		for (int i = 0; i < N; ++i)
		{
			/* code */
			cin>>arr[i];
		}


		int ans=0;

		for(int i=1;i<N;i++)
		{
			int incr = arr[i] - arr[i-1];
			if(incr > 0)
				ans += incr;
		}

		cout<<ans<<'\n';
	}
}
