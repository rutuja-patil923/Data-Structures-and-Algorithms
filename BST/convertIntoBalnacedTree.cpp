
void inorder(Node* root,vector<Node*>&in)
{
	if(root)
	{
		inorder(root->left,in);
		in.push_back(root);
		inorder(root->right,in);
	}
}
Node* solve(Node* root,int low,int high,vector<Node*> in)
{
	if(low>high)
		return NULL;

	int mid=(low+high)/2;
	Node* root = in[mid];

	root->left=solve(root->left,low,mid-1,in);
	root->right=solve(root->right,mid+1,high,in);

	return root;
}
Node* convertIntoBalanced(Node* root)
{
	vector<Node*> in;
	inorder(root,in);

	return solve(root,0,in.size()-1);
}