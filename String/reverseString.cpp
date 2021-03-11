// Question Link: https://leetcode.com/problems/reverse-string/
// Difficulty Level : Easy
// Input: ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Expected Space Complexity : O(1)

// Approch : with O(1) extra we need to do inplace swapping


#include<bits/stdc++.h>
using namespace std;

void reverseString(char s[],int n)
{
	int i=0;
    int j=n-1;
    
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;j--;
    }
}
void print_Array(char arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

//main function
int main()
{
 	int n;cin>>n;
 	// input string as a character array
 	char arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
 	
 	reverseString(arr,n);
 	print_Array(arr,n);

 	return 0;
}



