 bool check(Node *root)
    {
        int level=0,flag=-1;
        if(!root)
            return true;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
               Node* current=q.front();
               q.pop();
               if(!current->left && !current->right)
                {
                    if(flag==-1)
                        flag=level;
                    else
                    {
                        if(level!=flag)
                            return false;
                    }
                } 
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            level++;
        }
        return true;
        
    }