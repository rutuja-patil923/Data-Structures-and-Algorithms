// Question Link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
// Difficulty Level : Easy
// e.g Input: "test string" output: s:count = 2, t:count = 3
// Expected Time complexity : O(N)
// Expected Space Complexity : O(1)...[fix array of size of no. of alphabets in total i.e 26]

// Approch 1 : Use of Hashing
// Approch 2 : Mapping T.C-(NlogN) each element to insert in map takes O(logN) time S.C-O(k)...[0<k<=length of string]


// Approch 1
#include<bits/stdc++.h>
using namespace std;

void duplicates(string str)
{
	// store charater frequency 
	int freq[26]={0};
	
	for(int i=0;i<str.length();i++)
		freq[str[i]-'a']++;
		
	for(int i=0;i<26;i++)
	{
		if(freq[i]>1)
			cout<<(char)(i+'a')<<" : "<<freq[i]<<endl;
	}
}

//main function
int main()
{
 	string str;
 	cin>>str;
 	
 	duplicates(str);

 	return 0;
}



