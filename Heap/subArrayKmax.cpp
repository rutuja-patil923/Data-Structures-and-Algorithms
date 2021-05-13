#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[],int N,int k)
{
	priority_queue<pair<int,int>> pq;

	vector<int> ans;

	for(int i=0;i<k;i++)
		pq.push({arr[i],i});

	pair<int,int> temp=pq.top();
	ans.push_back(temp.first);

	for(int i=1;i+k<N;i++)
	{
		int start=i;

		pq.push({arr[i],i});
		temp = pq.top();

		while(temp.second < start)
		{
			pq.pop();
			temp = p.top();
		}

		ans.push_back(temp.first);
	}
	return ans;
}