long long  multiplyTwoLists (Node* l1, Node* l2)
{
        long long first=0;
        long long second=0;
        long long mod = 1000000007;
        while(l1 || l2)
        {
            if(l1)
            {
                first = ((first*10)%mod+l1->data%mod)%mod;
                l1=l1->next;
            }
            
            if(l2)
            {
                second = ((second*10)%mod+l2->data%mod)%mod;
                l2=l2->next;
            }
        }
        
        return ((first%mod)*(second%mod))%mod;
        
}