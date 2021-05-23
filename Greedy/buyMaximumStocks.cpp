#include<bits/stdc++.h>
using namespace std;
struct prices
{
	int price;
	int maxStocks;
};
bool compare(prices p1,prices p2)
{
	if(p1.price == p2.price)
		return p1.maxStocks > p2.maxStocks;
	return p1.price < p2.price;
}
int main()
{
	int N,K;
	cin>>N>>K;
	struct prices arr[N];
	for(int i=0;i<N;i++) 
	{
		cin>>arr[i].price;
		arr[i].maxStocks = i+1;
	}

	sort(arr,arr+N,compare);

	int stockPrice=0,ans=0;

	for(int i=0;i<N;i++)
	{
		int limit = min(arr[i].maxStocks,K/arr[i].price);

		ans += limit;

		K -= (arr[i].price * limit);
	}

	cout<<ans;

}