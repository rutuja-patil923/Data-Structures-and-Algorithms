#include<bits/stdc++.h>
using namespace std;
typedef struct Job{
	int arrival;
	int burst;
	int id;
}Job;
struct compare{
	bool operator()(const Job &j1,const Job & j2)
	{
		return j1.burst > j2.burst;
	}
};
bool comp(const Job &j1,const Job & j2)
{
	return j1.arrival < j2.arrival;
}
int main()
{
	int N;cin>>N;

	Job arr[N];
	//int first_job,first_burst,first_arrival=INT_MAX;

	for(int i=0;i<N;i++)
	{
		cin>>arr[i].arrival>>arr[i].burst>>arr[i].id;
		// if(arr[i].arrival < first_arrival)
		// {
		// 	first_arrival = arr[i].arrival;
		// 	first_job = arr[i].id;
		// 	first_burst = arr[i].burst;
		// }
	}
	sort(arr,arr+N,comp);
	//cout<<N<<" ";
	priority_queue<Job,vector<Job>,compare> pq;
	// first_job=arr[0].id;
	// first_burst=arr[0].burst;
	// for(int i=0;i<N;i++)
	// {
	// 	if(arr[i].id !=first_job && arr[i].arrival <= first_burst)
	// 	{
	// 		pq.push(arr[i]);
	// 		arr[i].id = -1;
	// 	}
	// }
	// cout<<first_job<<" ";
	pq.push(arr[0]);
	arr[0].id=-1;
	// cout<<first_burst<<" ";
	// cout<<pq.size();
	int i=1,current_time=0;
	while(!pq.empty())
	{
		Job tmp = pq.top(); 
		pq.pop();
		cout<<tmp.id<<" ";
		current_time += tmp.burst;

		while(i<N)
		{
			if(arr[i].arrival <= current_time)
				pq.push(arr[i]);
			else
				break;
			i++;
		}

		// for(;i<N;i++)
		// {
		// 	if(arr[i].id !=-1 && arr[i].arrival <= tmp.burst)
		// 	{
		// 		pq.push(arr[i]);
		// 		arr[i].id=-1;
		// 	}
		// }

		// if(pq.empty())
		// {
		// 	for(int i=0;i<N;i++)
		// 	{
		// 		if(arr[i].id!=-1)
		// 		{
		// 			pq.push(arr[i]);
		// 			arr[i].id=-1;
		// 			break;
		// 		}
		// 	}
		// }
	}
}