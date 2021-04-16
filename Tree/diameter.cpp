// Question Link : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

int height(TreeNode* root)
{
	if(!root)
		return 0;

	return 1+max(height(root->left),height(root->right));
}
int diameter(TreeNode* root)
{
	if(!root)
		return 0;

	int leftHeight=height(root->left);
	int rightHeight=height(root->right);

	return max(1+leftHeight+rightHeight,max(diameter(root->left),diameter(root->right)));
}