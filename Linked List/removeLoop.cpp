// Quesion Link : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(!head) return;
        
        Node* slow=head,*fast=head;
        Node* prev;
        
        // floyd cycle detection algorithm
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            prev=fast->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }

        // if no loop present
        if(slow!=fast) return;
        //Node* prev;
        slow=head;

        // if loop is starting from first node itself 
        if(fast==head)
        {
            prev->next=NULL;
            return;
        }
        
        //finding node before starting point of loop
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            //prev=fast;
            fast=fast->next;
        }
        //detaching link
        fast->next=NULL;
        return ;    
        
    }
};