
vois solve(Node* root,Node* prev)
{
	if(root)
	{
		solve(root->left,prev);
		prev->right=root;
		prev->left=NULL;
		prev=root;
		solve(root->right,prev);
	}
}
Node* flattenTree(Node* root)
{
	Node* dummy=new Node(0);

	Node* prev= dummy;

	solve(root,prev);
}