// Time Complexity : O(NlogN)

#include<bits/stdc++.h>
using namespace std;

int main()
{
 	string str;
 	cin>>str;

 	int freq[26]={0};

 	for (int i = 0; i < str.length(); ++i)
 	{
 		/* code */
 		freq[str[i]-'a']++;
 	}

 	priority_queue<pair<int,char>> pq;

 	for (int i = 0; i < 26; ++i)
 	{
 		/* code */
 		if(freq[i]!=0)
 			pq.push({freq[i],(char)(i+'a')});
 	}

 	pair<int,char> prev={-1,'*'};
 	string res="";

 	// Logic here is we're finding letters to compensate for the letter which higher frequency 
 	// suppose take example of aaaabb
 	// freq(a) = 4
 	// freq(b) = 2
 	// iteration 1 -> res = "a" freq(a) = 3 pop(a)
 	// iteration 2 -> res = "ab" freq(a) = 3 freq(b) = 1 pop(b)
 	// iteration 3 -> res = "aba" freq(a) = 2 pop(a) 
 	// iteration 4 -> res = "abab" freq(a) = 2 freq(b) = 0 pop(b)
 	// pq will be empty because no remaining letter to compensate a
 	// therefore at last will check if both lengths matches or not
 	while(!pq.empty())
 	{
 		auto it = pq.top();pq.pop();

 		res += (it.second);

 		if(prev.first > 0)
 			pq.push(prev);

 		it.first--;
 		prev = it;
 	}

 	cout<<str<<" "<<res<<endl;

 	if(str.length()!=res.length())
 		cout<<"Not Possible!";
 	else
 		cout<<"Possible!";
}