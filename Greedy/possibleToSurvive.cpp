#include<bits/stdc++.h>
using namespace std;

int main()
{
	int S,N,M;
	cin>>S>>N>>M;

	int foodAvailable=0,i,days=0;
	for(i=1;i<=S;i++)
	{
		if(foodAvailable>=M)
		{
			foodAvailable -= M;
			continue;
		}

		if(i%7)
		{
			foodAvailable += N;
			days++;
		}

		if(foodAvailable < M)
		{
			cout<<"No";
			break;
		}
		foodAvailable -= M;
	}

	if(i==S+1)
		cout<<"YES"<<" "<<days;
}