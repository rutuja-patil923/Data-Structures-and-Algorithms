#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	// frequency array to store frequency of each character
	int freq[26]={0};

	// will store character with maximum frequency
	char maxFreqChar;
	int mx = 0;


	// for loop to store frequency
	for(int i=0;i<str.length();i++)
	{
		freq[str[i]-'a']++;

		if(freq[str[i]-'a']>mx)
		{
			mx = freq[str[i]-'a'];
			maxFreqChar = str[i];
		}
	}

	// now will check will it be possible to rearrange character or not
	// we're taking length + 1
	// reason being for odd length will give correct answer
	if(mx >(str.length()+1)/2)
		cout<<"Not Possible!";
	else
	{
		// string to store result
		// we need to declare string of length str beforehand
		int n = str.length();
		string res (n,' ');
		int index = 0;

		// so idea is first will fill all the even positions with character with maximum frequency
		// if some positions still remains will fill with remaining characters
		// so that adjacent characters will never be same

		while(freq[maxFreqChar-'a']>0)
		{
			res[index] = maxFreqChar;
			index+=2;
			freq[maxFreqChar-'a']--;
		}

		// now as we have fill even positions with character with maximum frequency
		// time to fill remaining even positions + odd positions

		for(int i=0;i<26;i++)
		{
			while(freq[i] > 0)
			{
				// this condition checks if even positions are still remaining or not
				index = (index>=n) ? 1 : index;
				res[index] = (char)(i+'a');
				freq[i]--;
				index += 2;
			}
		}

		cout<<res<<endl;
	}
	
}