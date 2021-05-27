// this brute force solution for this question
// O(N^2)
#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	string str;
	cin>>str;

	int i=0,j;

	while(i<str.length())
	{
		if(str[i]==str[i+1])
		{
			j = i+1;
			while(j<str.length() && str[i]==str[j])
				j++;
			if(j<str.length())
			{
				char tmp=str[j];
				str[j]=str[i+1];
				str[i+1]=tmp;
			}
			// swap(str[i+1],str[j]);
		}
		i++;
	}

	//cout<<ans;
	//cout<<str;
	for(int i=1;i<str.length();i++)
	{
		if(str[i]==str[i-1])
		{
			cout<<"Not Possible";
			return 0;
		}
	}

	cout<<str;
}