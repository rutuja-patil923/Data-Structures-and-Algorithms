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
void preorder(Node *root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root){
    if(root){
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void solve(Node* root)
 {
	unordered_map<Node*,int> up;

 	stack <Node*> st;

 	Node* current=root;

    st.push(root);

    while(!st.empty())
    {
        Node* current=st.top();

        if(up[current]==0)
            cout<<current->data<<" ";
        else if(up[current]==1)
        {
            if(current->left)
                st.push(current->left);
        }
        else if(up[current]==2)
        {
            if(current->right)
                st.push(current->right);
        }
        else
            st.pop();
        up[current]++;
    }
	
 }
int main()
{
	Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);

    preorder(root);
    cout<<endl;
	solve(root);
    cout<<endl;

	return 0;
}


 
