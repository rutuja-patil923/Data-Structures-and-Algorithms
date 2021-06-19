// question Link : https://codedrills.io/problems/rotate-and-match

#include<string>
#include<bits/stdc++.h>
using namespace std;
class RotateAndMatch {
public:
	
	bool isMatchPossible(std::string s, std::string target) 
	{
		
		
		if(s.length()!=target.length()) 
			return false;
		int i=0,j=0;
		int N = target.length();
		while(i < s.length()*2 && j<target.length())
		{
			if(i>=N)
			{
				if(j>0 && s[i%N]==target[j])
					j++;
				else return false;
			}
			else if(s[i]==target[j])
				j++;
			else
				j=0;
			
			i++;
		}
		if(j>=target.length()) return true;
		return false;

	}
};