struct node* getEnd(struct node* head)
{
    while(head!=NULL && head->next!=NULL)
        head = head ->next;
    return head;
}
struct node* partition(struct node* head,struct node* end,struct node** newHead,struct node** newEnd)
{
    struct node* prev = NULL,*pivot = end,*current = head,*tail=pivot;
    
    while(current!=pivot)
    {
        if(current->data < pivot->data)
        {
            if(*newHead == NULL)
                *newHead = current;
            prev = current;
            current = current -> next;
        }
        else
        {
            if(prev)
                prev->next = current->next;
            struct node* temp = current->next;
            current->next = NULL;
            tail->next= current;
            tail= current;
            current=temp;
        }
    }
    if(*newHead == NULL)
        *newHead = pivot;
    *newEnd = tail;
    return pivot;
}
struct node* solve(struct node* head,struct node* end)
{
    if(!head || head==end)
        return head;
    struct node* newHead= NULL,*newEnd=NULL;   
    struct node* pivot = partition(head,end,&newHead,&newEnd);
    
    if(newHead != pivot)
    {
        struct node* tail = newHead;
        while(tail->next != pivot)
            tail=tail->next;
            
        tail->next = NULL;
        
        newHead = solve(newHead,tail);
        
        tail = getEnd(newHead);
        tail->next = pivot;
    }
    
    pivot->next = solve(pivot->next,end);
    return newHead;
}
void quickSort(struct node **headRef) {
    *headRef = solve(*headRef,getEnd(*headRef)); 
}
