
bool Anagrams(Node* root1,Node* root2)
{

	if(!root2 && !roo1)
		return true;

	if(!root1 || !root2)
		return false;

	queue<Node*> tree1,tree2;

	tree1.push(root1);
	tree2.push(root2);

	while(!tree1.empty() && !tree2.empty())
	{
		int size=tree1.size();
		set<int> t1,t2;

		for(int i=0;i<size;i++)
		{
			Node* current1=tree1.front();tree1.pop();
			Node* current2=tree2.front();tree2.pop();

			t1.insert(current1->data);
			t2.insert(current2->data);

			if(current1->left)
				tree1.push(current1->left);
			if(current1->right)
				tree1.push(current1->right);
			if(current2->left)
				tree2.push(current2->left);
			if(current2->right)
				tree2.push(current2->right);
		}

		if(t1!=t2)
			return false;
	}

	return true;
}