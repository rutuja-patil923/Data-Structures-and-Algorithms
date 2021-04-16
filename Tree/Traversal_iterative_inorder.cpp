 
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
	//cout<<"Entry";
 	stack <Node*> st;

 	Node* current=root;

 	while(!st.empty() || current)
 	{
 		//	cout<<"Entry";
 		if(current)
 		{
 			st.push(current);
 			current=current->left;
 		}
 		else
 		{
 			current=st.top();
 			st.pop();
 			cout<<current->data<<" ";
 			current=current->right;
 		}
 	}
 }
int main()
{
	Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);

    inorder(root);
    cout<<endl;
	solve(root);
    cout<<endl;

	return 0;
}


 
