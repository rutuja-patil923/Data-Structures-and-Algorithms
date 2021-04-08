// Question Link : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
// Time Complexity : O(N)
// Space Complexity : O(N)

//****************************************************************************************************************

Node * removeDuplicates( Node *head) 
{
     
        // check if any number has been repeated
        unordered_map<int,int> umap;
        Node* prev=NULL,*current=head;
        
        while(current)
        {
            // if number is already present then prev position will not change
            if(umap.find(current->data)!=umap.end())
                prev->next=current->next;
            // otherwise prev will change
            else
                prev=current;
            umap[current->data]=1;
            current=current->next;
        }
        
        return head;
}