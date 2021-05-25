//3
//6
//1000 1030 1
//1010 1030 1
//1000 1020 2
//1030 1230 2
//1200 1230 3
//900  1005 1

#include<bits/stdc++.h>
using namespace std;

// struct train
// {
// 	int arrival;
// 	int departure;
// 	int platform;
// }

bool compare(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second < p2.second;
}
int main()
{
    // input format
    // platforms = available platforms
    // trains = total no. of trains
    // arr = array containing information for trains
    int platforms;
    cin>>platforms;

 	int trains;
 	cin>>trains;

 	// struct train arr[trains];
 	vector<vector<pair<int,int>>> V(platforms+1);
 	int arrival,departure,platform;
 	for(int i=0;i<trains;i++)
 	{
 		// cin>>arr[i].arrival>>arr[i].departure>>arr[i].platform;
 		cin>>arrival>>departure>>platform;
 		V[platform].push_back({arrival,departure});
 	}
	
	for(int i=1;i<=platforms;i++)
	{
		sort(V[i].begin(),V[i].end(),compare);
		for(int j=0;j<V[i].size();j++)
			cout<<V[i][j].first<<"->"<<V[i][j].second<<'\n';
		cout<<'\n';
	}
 	int ans=0;

 	for(int i=1;i<=platforms;i++)
 	{
 		int cnt=1;
		sort(V[i].begin(),V[i].end(),compare);
 		int limit=V[i][0].second;

 		for(int j=1;j<V[i].size();j++)
 		{
 			if(V[i][j].first > limit)
 			{
 				cnt++;
 				limit = V[i][j].second;
 			}
 		}
 		ans += cnt;
 	}

 	cout<<ans;

}
