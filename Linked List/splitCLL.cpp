// Question Link : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
// Expected Time Complexity: O(N)
// Expected Auxilliary Space: O(1)

//**********************************************************************************************************

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow=head,*fast=head,*prev;

    	// finding middle of list    
        while(fast->next!=head && fast->next->next!=head)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        *head1_ref=head;

        // this condition meaning is list is having odd number of nodes
        if(fast->next==head)
        {
            fast->next=slow->next;
            slow->next=head;
            *head2_ref=fast->next;
        }

        // even number of nodes
        else
        {
            fast->next->next=slow->next;
            slow->next=head;
            *head2_ref=fast->next->next;
        }
}