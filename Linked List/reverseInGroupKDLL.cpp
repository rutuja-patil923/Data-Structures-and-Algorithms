// Question Link : https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
// Time Complexity : O(N)
// Space Complexity : O(N/K) 

//**********************************************************************************************

Node* reverseSizeK(Node* head,int k)
{
	if(!head)
		return head;

	Node* current=head,*next=NULL,*prevNode=NULL;

	int cnt=0;

	while(current && cnt<k)
	{
		next=current->next;
		prevNode=current;
		Node* temp=current->prev;
		current->prev=current->next;
		current->next=temp;

		current=next;
		cnt++;
	}

	if(next)
	{
		// getting address of last node in next group of k nodes
		head->next=reverseSizeK(next,k);

		// prev should also be updated accordingly
		head->next->prev=head;
	}

	// see first group 
	prevNode->prev=NULL;

	// at last will return prev only
	return prevNode;
}