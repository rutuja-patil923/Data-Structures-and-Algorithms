void inorder(Node* root,Node** head,Node**prev)
    {
        if(root)
        {
            inorder(root->left,&(*head),&(*prev));
        
            if(!(*head))
            {
                (*head)=root;
                (*prev)=root;
            }
            else
            {
                (*prev)->right=root;
                root->left=(*prev);
                (*prev)=root;
            }
                
            inorder(root->right,&(*head),&(*prev));
        }
    }
    Node * bToDLL(Node *root)
    {
        int flag=0;
        if(!root)
            return NULL;
        
        Node* head=NULL,*prev=NULL;
        
        inorder(root,&head,&prev);
        
        return head;
    }