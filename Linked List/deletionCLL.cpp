// Question Link : https://www.geeksforgeeks.org/deletion-circular-linked-list/
// Time Complexity :
// Space Complexity :

//********************************************************************************************
Node* deletionCLL(Node* head,int val)
{
	// list is empty
	if(!head) return NULL;

	// list contains only one node
	if(head->next==head)
	{
		if(head->data==val) return head;
		else return NULL;
	}

	// if head node itself contains key
	if(head->data==val)
	{
		Node* prevHead=head;
		head=current->next;
		while(current->next!=prevHead)
			current=current->next;
		current->next=head;
		return head;

	}

	// starting from second node
	current=current->next;
	Node* prev;
	while(current->next!=head)
	{
		if(current->data==val)
		{
			prev->next=current->next;
			return head;
		}
		prev=current;
		current=current->next;
	}

	// no such data found
	return NULL;

}