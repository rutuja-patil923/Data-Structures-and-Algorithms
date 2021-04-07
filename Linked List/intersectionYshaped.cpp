// Question Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
// Time Complexity : O(N)
// Space Complexity : O(1)

//***************************************************************************************************************


// fn will calculate length of LL
int lengthLL(Node* head)
{
    int len=0;
    while(head)
    {
        len++;
        head=head->next;
    }
    return len;
}

// approch is to traverse LL with large length among both until both contains same nodes in LL
// and then traverse until address is same
int intersectPoint(Node* head1, Node* head2)
{
    int length1 = lengthLL(head1);
    int length2 = lengthLL(head2);
    
    // if second list is larger than first
    if(length1<length2)
    {
        swap(length1,length2);
        Node* temp=head1;
        head1=head2;
        head2=temp;
    }
    
    // traversing first LL
    for(int i=0;i<length1-length2;i++)
        head1=head1->next;
    
    while(head1!=head2)
    {
        head1=head1->next;
        head2=head2->next;
    }


    return head1->data;
    
}