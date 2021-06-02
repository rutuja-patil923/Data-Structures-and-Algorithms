// Max Heap Property : root should contain greater value as compared to it's subtrees
// Heap Property : Tree should be complete

    bool check(struct Node* root,int maximum)
    {
        if(root)
        {
            if(root->data>maximum)
                return false;
            if(root->right && !root->left)
                return false;
            return check(root->left,root->data) && check(root->right,root->data);
        }
        return true;
    }
    bool isHeap(struct Node * root)
    {
        return check(root,1005);
    }