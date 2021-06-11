Node *copyList(Node *head) {
    
    if(!head) return head;
    if(!head->next) return new Node(head->data);
    Node* current = head;
    
    while(current)
    {
        Node* temp = new Node(current->data);
        temp->next=current->next;
        current->next=temp;
        current=temp->next;
    }
    
    current = head;
    Node* front = current->next;
    
    while(current)
    {
        if(current->arb)
            front->arb = current->arb->next;
        current = front->next;
        if(current)
            front = current->next;
    }
    
    current = head;
    front=current->next;
    Node* res=front;
    
    while(front)
    {
        current->next = front->next;
        
        if(front->next)
            front->next = front->next->next;
        
        current = current->next;
        front=front->next;
    }
    return res;
}