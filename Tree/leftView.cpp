vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(!root)
        return ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        vector<int> v;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* current=q.front();q.pop();
            v.push_back(current->data);
            
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
        ans.push_back(v[0]);
    }
    
    return ans;
}