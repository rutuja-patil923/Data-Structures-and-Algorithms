void toSumTree(Node *root)
    {
        if(!root)
            return;
        
        if(!root->left && !root->right)
        {
            root->data=0;
            return;
        }
        
        int left=0;
        if(root->left)
            left=root->left->data;
        int right=0;
        if(root->right)
            right=root->right->data;
        
        toSumTree(root->left);
        toSumTree(root->right);
        
        int temp= left + right ;
        if(root->left)
            temp+= root->left->data;
        if(root->right)
            temp+=root->right->data;
            
        root->data=temp;
        
    }