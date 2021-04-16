 
#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void solve(Node* root)
{
	map<int,vector<int>> up;
	queue<pair<Node*,int>> q;

	q.push({root,0});

	while(!q.empty())
	{
		int size=q.size();

		for(int i=0;i<size;i++)
		{
			pair<Node*,int> p=q.front();q.pop();

			Node* curr_node=p.first;
			int curr_level=p.second;
			up[curr_level].push_back(curr_node->data);
			if(curr_node->left)
				q.push({curr_node->left,curr_level+1});
			if(curr_node->right)
				q.push({curr_node->right,curr_level});
		}
	}

	for(auto it:up)
	{
		vector<int> v=it.second;

		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<'\n';
	}
}
int main()
{
	Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    
	solve(root);
    

	return 0;
}


 

