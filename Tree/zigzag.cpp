vector <int> zigZagTraversal(Node* root)
{
	int start=0,end=0;
	
	vector<int> ans;
	if(!root)
	    return ans;
	queue<Node*> q;
	
	q.push(root);
	int flag=0;
	
	while(!q.empty())
	{
	    int size=q.size();
	    for(int i=0;i<size;i++)
	    {
	        Node* current=q.front();q.pop();
	        ans.push_back(current->data);
	        
	        if(current->left)
	            q.push(current->left);
	        if(current->right)
	            q.push(current->right);
	        end++;
	    }
	    if(flag)
	        reverse(ans.begin()+start,ans.end());
	    flag=flag^1;
	    start=end;
	}
	return ans;
}