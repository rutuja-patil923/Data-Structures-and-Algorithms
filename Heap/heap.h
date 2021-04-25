#include<bits/stdc++.h>
using namespace std;

void max_heapify(int arr[],int index,int N)
{
	int left_child = 2*index;
	int right_child = 2*index+1 ;

	int largest;

	if(left_child<=N && arr[left_child]>arr[index])
		largest=left_child;
	else
		largest=index;

	if(right_child<=N && arr[right_child]>arr[largest])
		largest=right_child;

	if(largest!=index)
	{
		swap(arr[index],arr[largest]);
		max_heapify(arr,largest,N);
	}
}
void min_heapify(int arr[],int index,int N)
{
	int left_child = 2*index ;
	int right_child = 2*index+1 ;

	int smallest;

	if(left_child<=N && arr[left_child]<arr[index])
		smallest=left_child;
	else
		smallest=index;

	if(right_child<=N && arr[right_child]<arr[smallest])
		smallest=right_child;

	if(smallest!=index)
	{
		swap(arr[index],arr[smallest]);
		max_heapify(arr,smallest,N);
	}
}
void build_maxheap(int arr[],int N)
{

	for(int i=N/2;i>=1;i--)
	{
		max_heapify(arr,i,N);
	}
}
void build_minheap(int arr[],int N)
{

	for(int i=N/2;i>=1;i--)
	{
		min_heapify(arr,i,N);
	}
}
void heap_sort(int arr[],int N)
{
	build_maxheap(arr,N);

	int heap_size=N;

	for(int i=N;i>=2;i--)
	{
		swap(arr[1],arr[i]);
		heap_size-=1;
		
		max_heapify(arr,1,heap_size);
	}
}
int main()
{
	int arr[]={0,20,15,8,16,10,20,50};

	build_maxheap(arr,7);

	for(int i=1;i<=7;i++)
		cout<<arr[i]<<" ";
	cout<<'\n';
		
	heap_sort(arr,7);
	for(int i=1;i<=7;i++)
		cout<<arr[i]<<" ";
	
}