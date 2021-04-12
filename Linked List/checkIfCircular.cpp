// Question Link : https://practice.geeksforgeeks.org/problems/circular-linked-list/1
// Time Complexity : O(N)
// Space Complexity : O(1)

//**********************************************************************************

bool isCircular(Node *head)
{
   Node* current=head;
   // if list is empty or contains only one node
   if(!head || !(head->next)) return false;
   
   // if two nodes are in circular linked list
   if(head->next==head) return true;
   
   
   current=current->next;
   
   while(current)
   {
       current=current->next;
       if(current==head)
            return true;
   }
   return false;
}