 bool isValid(string s1,string s2)
    {
        int cnt=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
                cnt++;
            if(cnt>1) return false;
        }
        
        return true;
    }
    int shortDist(map<string,vector<string>>&mp,string beginWord,string endWord)
    {
        map<string,int> dist,visited;
        
        queue<string> q;
        q.push(beginWord);
        dist[beginWord]=1;
        visited[beginWord]=1;
        
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            
            for(string s:mp[curr])
            {
                if(visited[s]==0)
                {
                    q.push(s);
                    dist[s]=dist[curr]+1;
                    visited[s]=1;
                }
            }
        }
        
        if(dist.find(endWord)==dist.end())
            return 0;
        return dist[endWord];
        
    }
    void buildGraph(map<string,vector<string>> &mp,vector<string>& wordList,int N)
    {
        
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                
                if(isValid(wordList[i],wordList[j]))
                {
                        mp[wordList[i]].push_back(wordList[j]);
                        mp[wordList[j]].push_back(wordList[i]);
                }
                
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        wordList.insert(wordList.begin(),beginWord);
        
        int N = wordList.size();
        
        map<string,vector<string>> mp;
        
        buildGraph(mp,wordList,N);
        
        return shortDist(mp,beginWord,endWord);
    }
};