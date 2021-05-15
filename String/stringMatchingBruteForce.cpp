#include<bits/stdc++.h>
using namespace std;
int main()
{
	string text,pattern;
	cin>>text>>pattern;

	int N = text.length();
	int M = pattern.length();

	for(int i=0;i<N-M+1;i++)
	{
		int j = 0;

		while(text[i+j]==pattern[j])
			j++;

		if(j==M)
			cout<<"Pattern found at index "<<i<<'\n';
	}
}