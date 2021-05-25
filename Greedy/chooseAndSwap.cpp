// Question :
// You are given a string s of lower case english alphabets. You can choose any two characters in the string and 
// replace all the occurences of the first character with the second character and replace all 
// the occurences of the second character with the first character. 
// Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once


// Approch :
// for every letter will store it's first occurrence why ? -> e.g abba here at index 3 and 4 b comes first so if we change all occurrences of b to a string will become baab which is not smaller
// Traverse for evry letter in string
// and for every character search from 0 to index of that letter if any character contains index higher than it's index
// if such letter occurs it means there is character in string whose index is higher than current letter but occurs after current character

string chooseandswap(string a){
        
        int index[26];
        memset(index,-1,sizeof(index));
        
        for(int i=0;i<a.length();i++)
        {
            if(index[a[i]-'a']==-1)
                index[a[i]-'a']=i;
        }
            
        int i,j,flag=0;
        for(i=0;i<a.length();i++)
        {
            for(j=0;j<a[i]-'a';j++)
            {
                if(index[j] > i)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        if(flag)
        {
            char ch1 = a[i];
            char ch2 = (char)(j+'a');
            for(i=0;i<a.length();i++)
            {
                if(a[i]==ch1) a[i]=ch2;
                else if(a[i]==ch2) a[i]=ch1;
            }
        }
        
        return a;
    }