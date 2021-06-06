// in this problem we're dividing array in two arrays 



#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;cin>>N;
	int price[N],arr[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		price[i]=0;
	}

	int max_price=arr[N-1];

	// traversing from right to left
	// finding maximum price till i by buying at i and selling at max_price
	for(int i=N-2;i>=0;i--)
	{
		if(arr[i]>max_price)
			max_price = arr[i];

		price[i] = max(price[i+1],max_price - price[i]);
	}

	// traversing from left to right
	// here considering two stocks
	int min_price = arr[0];
	for(int i=1;i<N;i++)
	{
		if(arr[i] < min_price)
			min_price = arr[i];
		price[i] = max(price[i-1],price[i] + price[i] - min_price);
	}

	cout<<price[N-1];

}