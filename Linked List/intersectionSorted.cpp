// Question Link : https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
// Time Complexity : O(N+M)
// Space Complexity : O(N+M)

//********************************************************************************************************

Node* findIntersection(Node* head1, Node* head2)
{
    Node* ans=NULL,*current;
    
    // merge sort kind of
    while(head1 && head2)
    {
        if(head1->data<head2->data) 
        	head1=head1->next;
        else if(head1->data>head2->data) 
        	head2=head2->next;
        else
        {
            // creation of new node
            Node* newNode = new Node(head1->data);
            if(!ans)
            {
                ans=newNode;
                current=newNode;
            }
            else
            {
                current->next=newNode;
                current=newNode;
            }
            head1=head1->next;
            head2=head2->next;
        }
    }
    return ans;
}