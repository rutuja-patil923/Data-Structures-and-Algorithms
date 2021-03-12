// Question Link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
// Difficulty Level : Easy
// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Expected Time complexity : O(logN)
// Expected Space Complexity : O(1)

// Question Understanding : We need to find first and last occurrence position of x.

// Naive Approch : Traverse array and store positions T.C-O(N)
// Better Approch : as array is sorted Binary Search is useful here. O(logN)


#include<bits/stdc++.h>
using namespace std;

int firstPos(int arr[],int low,int high,int key)
{
    if(low>high) return -1;
    
    // no. elements in total array
    int n=(high-low) + 1;
    
    int mid;
    while(low<=high)
    {
        mid =(low+high)/2;
        
        // if array element at mid position is first occurence
        if(arr[mid] == key && (mid==0 || arr[mid-1]<key))
            return mid;
            
        // elements on right part are either greater or equal hence shifting towards left
        else if(arr[mid] >= key)
            high = mid-1;
            
        // elements on left part are less hence shifting towards right
        else
            low=mid+1;
    }
    return -1;
    
}
int lastPos(int arr[],int low,int high,int key)
{
    if(low>high) return -1;
    int n=(high-low) + 1;
    int mid,last;
    while(low<=high)
    {
        mid =(low+high)/2;
        
        if(arr[mid] == key && (mid==n || arr[mid+1]>key))
            return mid;
        else if(arr[mid] <= key)
            low = mid+1;
        else
            high=mid-1;
    }
    return -1;

}

//main function
int main()
{
 	int n,x;cin>>n>>x;
 	int arr[n];
 	for(int i=0;i<n;i++) cin>>arr[i];
	
	cout<<"First Occurrence : "<<firstPos(arr,0,n-1,x)<<endl;
	cout<<"Last Occurrence : "<<lastPos(arr,0,n-1,x);
 	return 0;
}



