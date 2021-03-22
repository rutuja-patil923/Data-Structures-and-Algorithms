// Question Link : https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#
// Input:
// N=3,  K=2 
// Output: 6
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1)

// Approch : we have to categorized into two parts 
//           1. last two contains same colour
//           2. last two contains differnt colour
// suppose N = 3 K = 3 {r,g,b}


//                         2                   |               3                          |   


// same ->      k ways rr,gg,bb                previous diffrent ways can e taken here
//                                             because at most two adjacent can be similar
//                                             ways = previous diffrent ways


// diffrent ->  each colour can make           now we can take previous both ways same   
//              pair with every other colour   as well as diffrent 
//              ways = k*(k-1)                 so total ways = (prev_tot)*(k-1)
//              {rg,rb,br,bg,gr,gb}

int solve(int N,int K)
{
	// initilize for N=2
	int same = K;
	int diff = K*(K-1);
	int total = (same + diff);

	// start from 3
	for(int i=3;i<=n;i++)
	{
		// same will get value of previous diffrent
		same = diff;

		// diffrent will be calculated as prev_tot * (K-1)
		diff = total * (K-1);

		total = same + diff;

	}

	return total;
}

int main()
{
	int N,K;
	cin>>N>>k;

	cout<<paintFences(N,K);
}