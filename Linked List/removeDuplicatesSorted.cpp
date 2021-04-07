// Question Link : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
// Time Complexity : O(N)
// Space Complexity : O(1)

//****************************************************************************************************************

Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(!head->next) return head;
    Node* current=head->next,*prev=head;
    
    while(current)
    {
        if(prev->data == current->data)
            prev->next=current->next;
        else
            prev=current;
        current=current->next;
    }
    return head;
}