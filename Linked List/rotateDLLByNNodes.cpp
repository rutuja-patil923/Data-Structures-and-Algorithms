// Question Link : https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/


// *************************************************************************************************

Node* rotate(Node* head,int N)
{

	Node* tail=head;

	// traversing to end of list
	while(tail->next) 
		tail=tail->next;

	Node* current=head;

	// traversing to new head
	for(int i=1;i<=N;i++)
		current=current->next;

	Node* prevNode=current->prev;

	// current node will become new head
	current->prev=NULL;

	// old head will be attached to end
	tail->next=head;
	head->prev=tail;

	// last node's next should be null
	prevNode->next=NULL;

	return current;
}