vector<int> leftBoundry(Node* root)
{
    vector<int> ans;
    Node* current=root->left;
    if(!current)
        return ans;
    
    while(current)
    {
        ans.push_back(current->data);
        
        if(current->left)
            current=current->left;
        else 
            current=current->right; 
    }
    return ans;
}
void leafNodes(Node* root,vector<int> &leaf)
{
    if(root)
    {
        leafNodes(root->left,leaf);
        if(!root->left && !root->right)
            leaf.push_back(root->data);
        leafNodes(root->right,leaf);
    }
    
}
vector<int> rightBoundry(Node*root)
{
    Node* current=root->right;
    vector<int> ans;
    if(!current)
        return ans;

    
    while(current)
    {
        ans.push_back(current->data);
        
        if(current->right)
            current=current->right; 
        else 
            current=current->left; 
    }
    return ans;
}
vector <int> printBoundary(Node *root)
{
    vector<int> ans;
    if(!root)
        return ans;
        
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return ans;
    }
    
    vector<int> left=leftBoundry(root);
    // cout<<"Left: ";
    // for(int i=0; i<left.size(); i++)
    //     cout<<left[i]<<" ";
    // cout<<endl;
    
    vector<int> leaf;
    leafNodes(root,leaf);
    // cout<<"Leaf: ";
    // for(int i=0; i<leaf.size(); i++)
    //     cout<<leaf[i]<<" ";
    // cout<<endl;
    
    vector<int> right=rightBoundry(root);
    // cout<<"Right: ";
    // for(int i=0; i<right.size(); i++)
    //     cout<<right[i]<<" ";
    // cout<<endl; 
     
    ans.push_back(root->data);
    if(left.size()!=0)
        for(int i=0;i<left.size()-1;i++)
            ans.push_back(left[i]);
        
    for(int i=0;i<leaf.size();i++)
        ans.push_back(leaf[i]);
        
    for(int i=right.size()-2;i>=0;i--)
        ans.push_back(right[i]);
        
    return ans;
}