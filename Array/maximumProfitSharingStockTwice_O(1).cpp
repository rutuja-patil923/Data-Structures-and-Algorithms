#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	int hold1=INT_MIN,hold2=INT_MIN,release1=0,release2=0;

	for(int i=0;i<N;i++)
	{
		release2 = max(release2,hold2 + arr[i]);
		hold2 = max(hold2 , release1-arr[i]);
		release1 = max(release1 , hold1+arr[i]);
		hold1 = max(hold1,-arr[i]);
	}

	cout<<release2;
	
}