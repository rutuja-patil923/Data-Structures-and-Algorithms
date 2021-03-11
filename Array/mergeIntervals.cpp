// Question Link: https://leetcode.com/problems/merge-intervals/
// Difficulty Level : Medium
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Expected Time complexity : O(N)
// Expected Space Complexity : O(1)

// Question Understanding : Some intervals will be given in which some of them are overlapping e.g. [1,3] and [2,4] are both overlapping intervals.

// Naive approch : with two nested loops for each interval find if any overlapping interval T.C-O(N^2)
// Better approch : sort intervals and then traverse array of intervals store them in stack each time compare it with top intervals at stack. T.C-O(NlogN) S.C-O(N)..[extra stack]
// Optimal approch : space complexity in better can be improved to O(1) as follows


#include<bits/stdc++.h>
using namespace std;

typedef struct interval
{
	int start;
	int end;
}inter;

bool compare(inter I1,inter I2)
{
	return (I1.start < I2.start);
}

void mergeIntervals(inter arr[],int n)
{
	// sorting intervals according to start
	sort(arr,arr+n,compare);
	
	// iterator to keep track of final interval array
	int index = 0;
	
	for(int i=1;i<n;i++)
	{
		// if intervals are overlapping check condition
		if(arr[index].end >= arr[i].start)
		{
			arr[index].end = max (arr[index].end,arr[i].end);
			
			// no need of below condition because starts are already sorted.
			//arr[index].start = min(arr[index].start,arr[i].end);
		}
		
		// no overlapping
		else
		{
			arr[++index]=arr[i];
		}
	}
	
	for(int i=0;i<=index;i++)
		cout<<arr[i].start<<" "<<arr[i].end<<endl;
}


//main function
int main()
{
 	int n;cin>>n;
 	inter arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i].start>>arr[i].end;
 	
 	mergeIntervals(arr,n);

 	return 0;
}



