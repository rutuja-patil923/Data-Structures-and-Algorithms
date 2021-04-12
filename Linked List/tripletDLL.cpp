// Question Link : https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
// Time Complexity : O(N^2)
// Space Complexity : O(1)

//*************************************************************************************
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
vector<vector<int>> solve(Node* head,int x)
{
	vector<vector<int>> triplet;
	Node* tail=head,*current=head;

	// last node
	while(tail->next!=NULL)
		tail=tail->next;

	while(current->next->next!=NULL)
	{
		int data = current->data;
		int key = x-data;
		

		Node* left=current->next,*right=tail;
		while(left!=right)
		{
			int lt = left->data;
			int rt = right->data;
			if(lt+rt < key)
				left=left->next;
			else if(lt+rt > key)
				right=right->prev;
			else
			{
				triplet.push_back({data,lt,rt});
				break;
			}
		}
		current=current->next;
	}

	return triplet;
}
int main()
{
	return 0;
}
