int cnt=0;
void solve(Node* root,int l,int h)
{
    if(root)
    {
        if(root->data>=l && root->data<=h)
        {
            cnt++;
            solve(root->left,l,h);
            solve(root->right,l,h);
        }
        else if(root->data<l)
            solve(root->right,l,h);
        else if(root->data>h)
            solve(root->left,l,h);
            
    }
}
int getCount(Node *root, int l, int h)
{
      cnt=0;
      solve(root,l,h);
      return cnt;
}