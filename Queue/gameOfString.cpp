int minValue(string s, int k){
        
        int freq[26]={0};
        
        if(k>=s.length())
            return 0;
        
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;
            
        priority_queue <int> pq;
        
        
        for(int i=0;i<26;i++) pq.push(freq[i]);
        
        while(k--)
        {
            int temp=pq.top();
            pq.pop();
            pq.push(temp-1);
        }
        
        int ans=0;
        
        while(!pq.empty())
        {
            int temp=pq.top();
            ans += (temp*temp);
            pq.pop();
        }
        
        return ans;
    }