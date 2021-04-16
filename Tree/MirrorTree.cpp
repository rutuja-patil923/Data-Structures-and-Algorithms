// Question Link : https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/


             //     5
             //    / \
             //   6   7
             //  / \  / \
             // 7   8 9  10

// bottom up approch 
// first going to depth and then swapping 
TreeNode* mirror(TreeNode* root)
{
	if(!root)
		return root;

	// left and right children addresses 
	TreeNode* left=mirror(root->left);
	TreeNode* right=mirror(root->right);

	// swapping will be done
	TreeNode* temp=left;
	left=right;
	right=temp;

	// at last will return root
	return root;
}