vector<int> topView(struct Node *root)
    {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            pair<Node*,int> p=q.front();q.pop();
            
            Node* current=p.first;
            int col=p.second;
            
            if(!mp[col])
                mp[col]=current->data;
                
            if(current->left)
                q.push({current->left,col-1});
            if(current->right)
                q.push({current->right,col+1});
        }
        
        vector<int> ans;
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
        
    	
    }