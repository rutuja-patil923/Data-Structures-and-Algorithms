



class Solution{
    public:
    unordered_map<int,int> up;
    int index=0;
    Node* solve(int pre[],int low,int high)
    {
        if(low>high)
            return NULL;
        Node* root=new Node(pre[index++]);
        
        if(low==high)
            return root;
            
        int mid=up[root->data];
        root->left=solve(pre,low,mid-1);
        root->right=solve(pre,mid+1,high);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        index=0;
        
        for(int i=0;i<n;i++)
            up[in[i]]=i;
            
        Node* root=solve(pre,0,n-1);
        return root;
    }
};