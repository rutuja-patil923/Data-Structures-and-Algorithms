#include<bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int N,string ip)
{
	int count=0,ans=0;

	int freq[26];
	for(int i=0;i<26;i++) 
		freq[i]=-1;
	// GACCBDDBAGEE
	for(int i=0;i<ip.length();i++)
	{
		//cout<<i<<" -> "<<freq[ip[i]-'a']<<" --> "<<ip[i]<<endl;
		if(freq[ip[i]-'A']==-1)
		{
			//cout<<"Entry"<<" ";
			freq[ip[i]-'A']=1;
			count++;
		}
		else 
		{
			freq[ip[i]-'A']=-1;
			count--;
		}
		//cout<<count<<" ";
		if(count>N && freq[ip[i]-'A']==1)
			ans++;
	}

	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		string ip;

		cin>>N>>ip;

		cout<<runCustomerSimulation(N,ip)<<'\n';
	}
}
