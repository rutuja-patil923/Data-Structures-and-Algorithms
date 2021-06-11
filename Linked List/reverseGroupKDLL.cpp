
void reverse(Node** headRef,Node* current)
{
	// suppose second node which will become first now
	current->prev=NULL;

	// first head will become second node and head will become second node
	current->next = *headRef;

	//for first node second node will become prev
	if(*headRef)
		*headRef -> prev = current;

	// new head will become second node
	*headRef = current;
}
Node* reverseDLL(Node* head , int k)
{
	Node* next,*current=head;

	int count=0;

	Node* newHead = NULL;

	while(current && count<k)
	{
		next = current->next;
		reverse(&newHead,current);
		current=next;
		count++;
	}

	if(next)
	{
		head->next = reverseDLL(next,k);
		head->next->prev=head;
	}

	return newHead;
}