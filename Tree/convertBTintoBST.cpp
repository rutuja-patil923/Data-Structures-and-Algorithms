#include<bits/stdc++.h>
using namespace std;

// to convert binary tree into binary search tree we need to remember one property of binary tree
//i.e inorder traversal of binary search tree is sorted
// so first find inorder traversal of binary tree and then make it sorted



// finding inorder traversal of binary tree
void inorder(int arr[],vector<int> &in,int index,int N)
{
	if(index>=N)
		return;
	inorder(arr,in,2*index+1,N);
	in.push_back(arr[index]);
	inorder(arr,in,2*index+2,N);
}

int minSwaps(vector<int> &in)
{
	int N=in.size();
	vector<int> original=in;
	map<int,int> mp;
	sort(in.begin(),in.end());

	//finding position of array elements in sorted array
	for(int i=0;i<in.size();i++)
		mp[in[i]]=i;

	int ans=0;
	int visited[N]={0};

	for(int i=0;i<N;i++)
	{
		int cycle_size=0;

		if(visited[i] || mp[original[i]]==i)
			continue;

		int j=i;

		while(!visited[j])
		{
			visited[j]=1;

			j=mp[original[j]];

			cycle_size++;
		}

		if(cycle_size>=2)
			ans += cycle_size-1;
	}

	return ans;

}

int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	vector<int> in;

	inorder(arr,in,0,N);

	cout<<minSwaps(in);
}









