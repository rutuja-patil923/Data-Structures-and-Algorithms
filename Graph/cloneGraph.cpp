class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) 
    {
        if(!node) 
            return NULL;
        if(mp.find(node)!=mp.end()) return mp[node];
        Node* current = new Node(node->val);
        mp[node]=current;
        for(int i=0;i<node->neighbors.size();i++)
            mp[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return mp[node];
    }
};