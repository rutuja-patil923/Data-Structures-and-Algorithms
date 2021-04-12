// Question Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Time Complexity : O(N)
// Space Complexity : O(N/k) recursion calls will be made

//**********************************************************************************************************************

    struct node *reverse (struct node *head, int k)
    { 
        struct node* current=head,*prev=NULL,*next=NULL;
        if(head==NULL)
            return NULL;
        int cnt=0;
        
        // reversing linked list in group 
        while(current && cnt<k)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            cnt++;
        }
        
        // head will point out to previous of next group which is actually last node of next linked list
        if(next)
            head->next=reverse(next,k);
        return prev;
    }