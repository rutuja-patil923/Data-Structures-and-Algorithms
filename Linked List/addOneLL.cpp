// Question Link : https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
// Time Complexity : O(N)
// Space Complexity : O(1)

// ***************************************************************************************************************

Node* reverseLL(Node* head)
{
    Node* current=head,*prev=NULL,*next;
    while(current)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
Node* addOne(Node *head) 
{
    head = reverseLL(head);
    // from starting onwards we're taking carry 1
    int carry=1;
        
    Node*current=head,*prev;
        
    while(current)
    {
        int temp= (current->data+carry)%10;
        carry = (current->data+carry)/10;
        current->data=temp;
        prev=current;
        current=current->next;
    }
     
    // if carry remains e.g 999   
    if(carry)
    {
        prev->next = new Node(carry);
    }
        
    head = reverseLL(head);
    return head;
}