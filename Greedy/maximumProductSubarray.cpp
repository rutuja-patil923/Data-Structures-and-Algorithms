
#include<bits/stdc++.h>
using namespace std;

//         1 1 -3 -4 2 -8 3 3
// pospod  1 1  1 12 24 
// negpod  1 1 -3 -4 -4
int main()
{
	int N;cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	// int negativeProd=1,posProd=1;

	// int ans=1;

	// for(int i=0;i<N;i++)
	// {
	// 	if(arr[i]<0)
	// 	{
	// 		posProd = max(posProd,arr[i]*negativeProd*posProd);
	// 		negativeProd = min(negativeProd,arr[i]);
	// 	}
	// 	else
	// 	{
	// 		posProd = posProd*arr[i];
	// 	}
	// }

	int countNegative=0,minNegative=-INT_MAX,countZero=0,product=1;

	for(int i=0;i<N;i++)
	{
		if(arr[i]<0)
		{
			countNegative++;
			minNegative = max(minNegative,arr[i]);
		}
		if(arr[i]==0)
			countZero++;
		if(arr[i]!=0)
			product *= arr[i];
	}

	if(countNegative%2)
	{
		
	}
	else if(countZero)


	cout<<posProd;
}
