	struct node *reverse (struct node *head, int k)
    { 
        // LL doesn't exist or group is of size of 1
        if(!head || k==1)
            return head;
            
        node* dummy = new node(0);
        dummy->next = head;
        node* current = dummy , *prev = dummy , *next = dummy;
        int len = 0;
        
        while(current->next!=NULL)
        {
            len++;
            current = current->next;
        }
        
        while(len>0)
        {
            current = prev->next;
            next = current->next;
            
            int limit = (len>=k) ? k : len;
            
            for(int i=1;i<limit;i++)
            {
                current->next = next->next;
                next -> next = prev->next;
                prev->next = next;
                next = current->next;
            }
            
            prev = current;
            len = (len>=k) ? len-k:0;
        }
        
        return dummy->next;
    }