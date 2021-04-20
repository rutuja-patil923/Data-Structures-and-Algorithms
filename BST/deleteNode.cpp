class Solution {
public:
    TreeNode* leftRightmost(TreeNode* root)
    {
        TreeNode* current=root->right;
        while(current->left)
            current=current->left;
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root)
        {
            if(root->val==key)
            {
                if(!root->left && !root->right)
                    return NULL;
                else if(!root->left || !root->right)
                {
                    if(!root->left)
                        return root->right;
                    else
                        return root->left;
                }
                else
                {
                    TreeNode* current=leftRightmost(root);
                    root->val=current->val;
                    root->right=deleteNode(root->right,current->val);
                    return root;
                }
            }
            else if(root->val<key)
                root->right=deleteNode(root->right,key);
            else
                root->left=deleteNode(root->left,key);
        }
        return root;
    }
};