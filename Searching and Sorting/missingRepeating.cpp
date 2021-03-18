// Question Link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Approch 1 : find diffrence between their sums = repeating number - missing number
//             find diffrence between squares = (repeating number - missing number)(repeating number + missing number)
//             find by adding and putting value of one of variable

// Approch 2 : Bit manipulation
//             same as finding two non-repeating numbers where every element appears twice in array
//             find XOR of all array elements and 1-N...XOR = missing ^ repeating
//             find set bit in XOR and make two containers and add array elements as well as 1-N
//             finally two elements will remain in each of this containers              

#include<bits/stdc++.h>
using namespace std;

vector<int> missineRepeating(int nums[],int N)
{
	int XOR = 0;
	for(int i=1;i<=N;i++)
		XOR ^= nums[i-1] ^ i;

	int setbit=0;
	for(;setbit<32;setbit++)
	{
		int check = 1<<setbit;
		if(check & XOR)
			break;
	}

	int first=0,second=0;

	for(int i=1;i<=N;i++)
	{
		int check = 1<<setbit;

		if(nums[i-1] & check)
			first ^= nums[i-1];
		else
			second ^= nums[i-1];
		if(i & check)
			first ^= i;
		else
			second ^= i;
	}

	vector<int> ans={first,second}
	for(int i=0;i<N;i++)
	{
		if(nums[i]==second)
		{
			swap(ans[0],ans[1]);
			break;
		}
	}

	return ans;
}

int main()
{
	int N;
	cin>>N;
	int nums[N];
	for(int i=0;i<N;i++) cin>>nums[i];

	vector<int> ans = missineRepeating(nums,N);
	cout<<ans[0]<<" "<<ans[1];
}