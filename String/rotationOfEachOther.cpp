// Question Link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
// Difficulty Level : Medium
// e.g Input: s1 = ABCD ,s2 = CDAB Output : true
// Expected Space Complexity : O(1)


// Question Understanding : we need tocheck if first string can we get first string by rotating second string

// Approch : Combine first string twice and find if second string is substring of that.

#include<bits/stdc++.h>
using namespace std;

bool isRotation(string str1,string str2)
{
	// if length is diffrent anyhow they're not rotation of each other
	if(str1.length() != str2.length())
		return false;
		
	string result = str1 + str1;
	
	return (result.find(str2) != string::npos);
}

//main function
int main()
{
 	string str1,str2;
 	cin>>str1>>str2;
 	
 	if(isRotation(str1,str2))
 		cout<<"True";
 	else
 		cout<<"False";
 	return 0;
}



