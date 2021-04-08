// Question Link : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// Time Complexity : O(N)
// Space Complexity : O(1)

//****************************************************************************************

Node* reverseDLL(Node * head)
{
    Node* current=head,*prev;
    
    while(current)
    {
        Node* temp = current->next;
        current->next=current->prev;
        current->prev=temp;
        prev=current;
        current=temp;
    }
    
    return prev;
}