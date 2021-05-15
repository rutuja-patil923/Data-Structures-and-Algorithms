#include<bits/stdc++.h>
using namespace std;
void printAllSubSequences(string input.string output)
{
	if(input.empty())
	{
		cout<<output<<endl;
		return;
	}
	printAllSubSequences(input.substr(1),output+input[0]);
	printAllSubSequences(input.substr(1),output);
}
int main()
{
	string input;
	string output="";

	cin>>input;

	printAllSubSequences(input,output);
}