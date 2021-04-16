bool isSumTree(Node* root)
    {
        if(!root) return true;
        if(!root->left && !root->right)
            return true;
            
        bool left =isSumTree(root->left);
        bool right = isSumTree(root->right);
        int sum=0;
        if(root->left)
            sum+=root->left->data;
        if(root->right)
            sum+=root->right->data;
            
        if(sum!=root->data)
            return false;
        
        root->data += sum;   
            
        return  left&&right; 
        
    }