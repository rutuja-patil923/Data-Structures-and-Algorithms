void findLevels(Node* root,int level)
{
    if(root)
    {
        findLevels(root->left,level+1);
        up[root->data]=level;
        findLevels(root->right,level+1);
    }
}
Node* LCA(Node* root,int a,int b)
{
    if(!root) return root;
    if(root->data==a || root->data==b) return root;
    
    Node* left=LCA(root->left,a,b);
    Node* right=LCA(root->right,a,b);
    
    if(left && right)
        return root;
    if(left)
        return left;
    return right;
}
int findDist(Node* root, int a, int b) {
    
    findLevels(root,0);
    
    Node* lca=LCA(root,a,b);
    
    int lca_level=up[lca->data];
    
    return (up[a]+up[b]-2*lca_level);
    
}