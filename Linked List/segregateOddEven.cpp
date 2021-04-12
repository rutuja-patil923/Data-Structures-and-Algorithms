// Question Link : https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1


//****************************************************************************************





Node* divide(int N, Node *head){
        
        Node* even=new Node(0);
        Node* odd= new Node(1);
        
        Node*tailEven=even,*tailOdd=odd;
        
        Node* current=head;
        
        while(current)
        {
            if((current->data)%2)
            {
                tailOdd->next=current;
                tailOdd=tailOdd->next;
            }
            else
            {
                tailEven->next=current;
                tailEven=tailEven->next;
            }
            
            current=current->next;
        }
        
        tailEven->next=odd->next;
        tailOdd->next=NULL;
        
        return even->next;
    }