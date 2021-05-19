string findSubString(string str)
    {
        map<int,int> mp,freq;
        for(int i=0;i<str.length();i++)
            mp[str[i]]=1;
        // mp will check total no. of distinct characters in string
        int diffch = mp.size();
        
        int left=0,right=0,ans=INT_MAX;
        int indexL,indexR;
        while(left <str.length() && right<=str.length())
        {
            // if size of diffrent characters is greater than equal to 
            // total no. of diffrent characters in string then move left pointer
            // otherwise move right pointer
            if(freq.size()>=diffch)
            {
                if(ans>right-left)
                {
                    ans = right-left;
                    indexL = left;
                    indexR = right;
                }
                freq[str[left]]--;
                if(freq[str[left]]==0) 
                    freq.erase(str[left]);
                left++;
            }
            else
            {
                freq[str[right]]++;
                right++;
            }
        }
        return str.substr(indexL,indexR-indexL);
    }