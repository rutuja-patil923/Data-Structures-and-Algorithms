

vector<int> reverseLevelOrder(Node *root)
{
	queue<Node*> q;
	stack<int> st;
	q.push(root);


	while(!q.empty())
	{
		Node* current=q.front();q.pop();

		st.push(current->data);
		if(current->right)
			q.push(current->right);
		if(current->left)
			q.push(current->left);

	}

	vector<int> ans;
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}