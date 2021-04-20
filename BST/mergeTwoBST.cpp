


Node* buildTree(vector<Node*> &resultant,int low,int high)
{
	if(low>high)
		return NULL;

	int mid=(low+high)/2;
	Node* root=resultant[mid];

	root->left=buildTree(resultant,low,mid-1);
	root->right=buildTree(resultant,mid+1,high);

	return root;
}

void mergeTwo(vector<Node*> &arr1,vector<Node*> &arr2,vector<Node*> &resultant)
{
	int i=0,j=0;

	while(i<arr1.size() && j<arr2.size())
	{
		Node* first=arr1[i];
		Node* second=arr2[j];

		if(first->data<second->data)
		{
			resultant.push_back(first);
			i++;
		}
		else
		{
			resultant.push_back(second);
			j++;
		}
	}

	while(i<arr1.size())
	{
		resultant.push_back(arr1[i]);
		i++;
	}

	while(j<arr2.size())
	{
		resultant.push_back(arr2[j]);
		j++;
	}
}
void inorder(Node* root,vector<int> & arr)
{
	if(root)
	{
		inorder(root->left,arr);
		arr.push_back(root);
		inorder(root->right,arr);
	}
}

Node* merge(Node* root1,Node* root2)
{
	vector<Node*> arr1,arr2;
	inorder(root1,arr1);
	inorder(root2,arr2);

	int N = arr1.size();
	int M = arr2.size();
	vector<Node*> resultant(N+M);

	mergeTwo(arr1,arr2,resultant);

	return buildTree(resultant,0,N+M-1);
}