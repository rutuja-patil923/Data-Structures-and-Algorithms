class Solution
{
    public:
    bool solve(Node* root,int mini,int maxi)
    {
        if(root)
        {
            if(root->data>mini && root->data<maxi)
                return (solve(root->left,mini,root->data)&&solve(root->right,root->data,maxi));
            else
                return false;
        }
        return true;
    }
    bool isBST(Node* root) 
    {
        int maxi=INT_MAX;
        
        return solve(root,-maxi,maxi);
    }
};