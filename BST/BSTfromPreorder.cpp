
Node* insert(Node* root,int key)
{
	if(!root)
		root=new Node(key);
	else if(root->data>key)
		root=insert(root->left,key);
	else
		root=insert(root->right,key);
	return root;
}
Node* prerderToBST(int pre[],int size)
{
	Node* root=NULL;

	for(int i=0;i<size;i++)
		root=insert(root,pre[i]);
	return root;
}