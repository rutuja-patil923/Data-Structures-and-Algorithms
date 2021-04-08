// Question Link : https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
// Time Complexity : O(N)
// Space Complexity : O(1)

vector<vector<int>> pairGivenSum(Node* head,int sum)
{
	Node*right=head,*left=head;
	vector<vector<int>> ans;

	while(right->next)
		right=right->next;


	while(left!=right)
	{
		int checkSum = left->data + right->data;
		if(checksum<sum)
			left=left->next;
		else if(checkSum>sum)
			right=right->prev;
		else
		{
			ans.push_back({left->data,right->data});
			left=left->next;
			right=right->prev;
		}
	}

	return ans;
}