typedef pair<int,Node*> pii;
Node *flatten(Node *root)
{
    Node* dummy = new Node(0);
    Node* current = dummy;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    
    Node* traverse=root;
    while(traverse)
    {
        pq.push({traverse->data,traverse});
        traverse = traverse->next;
    }
    //cout<<pq.size()<<endl;
    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        
        current->bottom=temp.second;
        current=current->bottom;
        
        if(temp.second->bottom)
        {
            pq.push({temp.second->bottom->data,temp.second->bottom});
        }
    }
    
    return dummy->bottom;
    
}