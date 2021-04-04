// Question: https://www.geeksforgeeks.org/reverse-a-linked-list/
// Time Complexity: O(N)
// Space Comlplexity : O(1)

// Other Approch : Using stack,store addresses in stack and then make last address as head and then traverse reverse until stack becomes empty
 

 //*******************************************************************************************************************

#include<bits/stdc++.h>
// Custom header file
#include"linkedList.h"

//Iterative
Node* reverseIter(Node* head)
{
	// stores current node in list
	Node* current=head;

	// address of node previous to current
	Node* prev=NULL;

	// nxt will store address of next node to current 
	Node* nxt;

	while(current)
	{
		// temprarily store next address
		nxt = current->next;

		// reversing node
		current->next=prev;

		// to attach next node to previous one
		prev=current;

		//moving forward
		current=nxt;
	}

	// current will be NULL at last
	// prev will contain address of last node
	return prev;
}

// recursive
Node* reverseRecur(Node* head)
{
	if(head->next==NULL)
		return head;
	// just retirning last node to each function
	Node* res = reverseRecur(head->next);
	head->next->next=head;

	// think aout first node at last 
	head->next=NULL;

	// returning address of last node of linked list
	return res; 
}

int main()
{
	// suppose LL is 1->2->3->4->5
	Node* head = createLL();
	displayLL(head);

	head=reverseRecur(head);
	displayLL(head);

	head=reverseIter(head);
	displayLL(head);
}
