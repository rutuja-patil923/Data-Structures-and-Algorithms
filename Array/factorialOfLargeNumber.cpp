// Question Link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
// Difficulty Level : Medium
// e.g Input: N = 10 output: 3628800
// Expected Time complexity : O(N) 
// Expected Space Complexity : O(1) 


// Question Understanding : we need to find factorial but while finding factorial method can't use simple method of just multiplying from 1 to that number because 
// int data type can't store large values like 100 factorial may contain greater than 50 digits. Not able to store in any of the data type
// need to write some algorithm so that can store each digit in array



#include<bits/stdc++.h>
using namespace std;

vector<int> factorialOfLargeNumber(int n)
{
	// as factorial of 5 = 2 * 3 * 4 * 5
	int multiply=2;
	
	// keep track of length of factorial
	int len=1;
	
	// array of digits
	int arr[100000]={0};
	arr[0]=1;
	
	while(multiply<=n)
	{
		// keep track of place to multiply digit from right
		// as in traditional multiplication
		int x=0;
		
		// stores remaining digits like in 120 after storing 0 num will contain 12 
		// it will continue till num becomes 0
		int num=0;
	
		// loop until length of factorial
		while(x<len)
		{
			// multiplication to each digit of first number as in traditional method starting from least significan digit i.e from right to left
			arr[x]=arr[x]*multiply;
			
			// will add carry if any from previous digit
			arr[x]+=num;
			
			num=arr[x]/10;
			
			//each array element stores a single digit
			arr[x]=arr[x]%10;
			
			// moving towards left
			x++;
		}
		
		// if any remaining digits
		while(num)
		{
			arr[len]=num%10;
			num/=10;
			len++;
		}
		
		// factorial means multiplication from 1 to n so increasing multiply variable
		multiply++;
	}
	
	vector<int> ans;
	
	for(int i=len-1;i>=0;i--)
		ans.push_back(arr[i]);
			
	return ans;
}

//main function
int main()
{
 	int n;cin>>n;
 	
 	vector <int> ans=factorialOfLargeNumber(n);
 	
 	for(auto it:ans) cout<<it;
 	return 0;
}


