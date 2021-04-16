
int solve(Node* root,int &ans)
{
	if(!root)
		return 0;


	root->data += solve(root->right,ans) + solve(root->left,ans);

	ans=max(ans,root->data);

	return root->data;

}

int largestSumTree(Node* root)
{
	int ans=INT_MIN;

	solve(root,ans);

	return ans;
}