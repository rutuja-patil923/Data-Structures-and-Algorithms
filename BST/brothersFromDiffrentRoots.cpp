set<int> tree1;
vector<int> tree2;
void inorder(Node* root,bool flag)
{
    if(root)
    {
        inorder(root->left,flag);
        if(!flag)
            tree1.insert(root->data);
        else
            tree2.push_back(root->data);
        inorder(root->right,flag);
    }
}
int countPairs(Node* root1, Node* root2, int x)
{
    bool flag=false;
    tree1.clear();
    tree2.clear();
    inorder(root1,flag);
    flag=true;
    inorder(root2,flag);
    int ans=0;
    
    for(int i=0;i<tree2.size();i++)
    {
        //cout<<x-tree2[i]<<" ";
        if(tree1.find(x-tree2[i])!=tree1.end())
            ans++;
    }
    return ans;
}