Node* merge(Node* l1,Node* l2)
    {
        Node* dummy = new Node(0);
        Node* current = dummy;
        
        while(l1 && l2)
        {
            if(l1->data<=l2->data)
            {
                current->next=l1;
                l1=l1->next;
            }
            else
            {
                current->next=l2;
                l2=l2->next;
            }
            current=current->next;
        }
        current->next = l1 ? l1:l2;
        return dummy->next;
    }
    Node* middle(Node* head)
    {
        Node* slow = head ,*prev;
        Node* fast = head ;
            
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(!fast)
        {
            prev->next=NULL;
            return slow;
        }    
        Node* res = slow->next;
        slow->next=NULL;
        return res;   
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next) 
            return head;
        if(head)
        {
            Node* mid = middle(head);
            head = mergeSort(head);
            mid = mergeSort(mid);
            head = merge(head,mid);
        }
        return head;
    }