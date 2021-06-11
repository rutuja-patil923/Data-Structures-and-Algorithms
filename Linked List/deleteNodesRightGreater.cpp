    Node *compute(Node *head)
    {
        stack<Node*> st;
        Node* current=head;
        
        while(current)
        {
            while(!st.empty() && st.top()->data < current->data)
                st.pop();
                
            if(st.empty())
                head = current;
            else
                st.top()->next=current;
            st.push(current);
            current = current->next;
        }
        
        return head;
    }