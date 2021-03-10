// Question Link: https://practice.geeksforgeeks.org/problems/power-set4302/1
// Difficulty Level : Medium

//Input : str = "abc"
//Output: a ab abc ac b bc c​
//Explanation : There are 7 substrings that 
//can be formed from abc

// Expected Time complexity : O(2^N)
// Expected Space Complexity : O(N* 2^N)

// Question Understanding : Given a string S we need to find all possible substrings of the string in lexicographically-sorted order

// Approch : bit manipulation can be used here
// e.g. Suppose length of string is 3 then take 1<<3 -1 =7 0111 
// from 0000 to 0111 check if bit is set at particular position then take character at that position


#include<bits/stdc++.h>
using namespace std;

void powerSet(string str)
{
	// instead of sorting whole ans array afterwards which will give complexity O( 2^N log (2^N)) sort string at first
	sort(str.begin(),str.end());
	
	// this contains all substrings
	vector <string> ans;
	
	// why ? suppose length of string is 3 then 1<<3 will give 1000 which is 8; 8-1 = 7 = 0111 which is mask of length 3 which is of string's length
	int len = (1<<str.length())-1;
	
	// traverse from 0000 to 0111
	for(int i=0;i<=len;i++)
	{
		string temp="";
		for(int bit=0;bit<32;bit++)
		{
			int check = 1<<bit;
			
			if(check & i)
				temp.push_back(str[bit]);
		}
		
		ans.push_back(temp);
	}
	
	for(auto it : ans)
		cout<<it<<endl;
}

//main function
int main()
{
 	string str;
 	cin>>str;
 	
 	powerSet(str);

 	return 0;
}



