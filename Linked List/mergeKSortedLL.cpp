class Solution{
  public:
    //Function to merge K sorted linked list.
    typedef pair<int,Node*> pii;
    Node * mergeKLists(Node *arr[], int K)
    {
        Node* dummy = new Node(0);
        Node* current = dummy;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        for(int i=0;i<K;i++)
            pq.push({arr[i]->data,arr[i]});
            
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            
            current->next = temp.second;
            current=current->next;
            
            if(temp.second->next!=NULL)
            {
                Node* ptr = temp.second ->next;
            
                pq.push({ptr->data,ptr});
            }
        }
        
        return dummy->next;
    }