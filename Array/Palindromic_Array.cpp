// Question Link: https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
// Difficulty Level : Basic
// e.g Input: 111 222 333 414 5 output: 1 [all elements are palindromic]
// Time complexity : O(N) [Traversing array once]
// Space Complexity : O(1) 

// basic concept here to use is palindromic concept
// some number is plaindrome when it's reverse is exactly eual to that number itself
// same concept will use here


#include<bits/stdc++.h>
using namespace std;

int isPalindrome(int x)
{
	// store x temprary before applying any operations on it.
	int temp=x;
	
	int reverse=0;
	while(x)
	{
		int reminder=x%10;
		reverse=(reverse*10)+ reminder;
		x/=10;
	}
	
	// temp has value of x
	if(reverse==temp)
		return 1;
	return 0;
}

//main function
int main()
{
 	//taking array input
	int n;cin>>n;
 	int a[n];
 	for(int i=0;i<n;i++) cin>>a[i];
 	
 	int flg=1;// flg will keep track if any array element is not palindromic
 	
 	for(int i=0;i<n;i++)
 	{
 		if(!isPalindrome(a[i]))
		{
			flg=0;
			break;	
		}	
	}
 	if(!flg)
 		cout<<"Array is not Palindromic";
 	else
 		cout<<"Array is Palindromic";
 	
}


