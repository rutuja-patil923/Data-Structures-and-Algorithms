// Question Link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#
// Difficulty Level : Basic
// e.g Input: abba output: 1
// Time complexity : O(N) [where N is length of string]
// Space Complexity : O(1) [Only use of temporary variable]


#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s)
{
	int i=0,j=s.length()-1;
	
	// iterate over loop till middle to check each letter is equal
	while(i<j)
	{
		if(s[i]!=s[j])
			return 0;
		i++;
		j--;
	}
	
	return 1;
}

//main function
int main()
{
 	string s;cin>>s;
 	
 	//isPalindrome() will return 1 if string is palindrome otherwise 0
	if(isPalindrome(s))
 		cout<<"String is Palindromic";
 	else
 		cout<<"String is not Palindromic";
 	
 	return 0;
}


