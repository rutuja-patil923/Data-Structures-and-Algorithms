bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length()) return false;
        char first[26],second[26];
        for(int i=0;i<26;i++) 
        {   
            first[i]='*';
            second[i]='*';
        }
        
        for(int i=0;i<str1.length();i++)
        {
            if(first[str1[i]-'a']=='*' && second[str2[i]-'a']=='*')
            {
                first[str1[i]-'a']=str2[i];
                second[str2[i]-'a']=str1[i];
            }
            else if(first[str1[i]-'a']!=str2[i] || second[str2[i]-'a']!=str1[i])
                return false;
        }
        return true;
    }