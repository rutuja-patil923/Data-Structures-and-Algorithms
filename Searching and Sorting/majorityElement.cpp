// Question Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Naive Approch : sort elements and keep track of count O(NlogN)
// Better Approch : Use of Hashing O(N) O(N)
// Optimal Approch : Moore Voting Algorithm O(N) O(1)


#include<bits/stdc++.h>
using namespace std;

// moore voting algorithm
int majorityElement(int a[],int size)
{
	int element,cnt=0;
    for(int i=0;i<size;i++)
    {
        if(cnt==0) 
        	element=a[i];
        if(a[i]==element) 
        	cnt++;
        else 
        	cnt--;
    }
        
    // if majority element being last element if no. of elements are odd
    // check again if element is actually majority or not
    cnt=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==element) cnt++;
    }
        
    return cnt > size/2 ? element : -1;
}
int main(){

	int N;cin>>N;
	int arr[N];
	for(int i=0;i<N;i++) cin>>arr[i];

	cout<<majorityElement(arr,N);
}