// Question Link : https://practice.geeksforgeeks.org/problems/circular-linked-list/1
// Time Complexity : O(N)
// Space Complexity : O(1)

bool isCircular(Node *head)
{
   Node* current=head;
   if(!head || !(head->next)) return false;
   
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