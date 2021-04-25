string FirstNonRepeating(string A)
{
		    
		    int temp[26]={0};
		    
		    string ans="";
		    
		    
		    queue<char> q;
		    
		    for(int i=0;i<A.length();i++)
		    {
		      
		        temp[A[i]-'a']++;
		        q.push(A[i]);
		        while(!q.empty() && temp[q.front()-'a']>=2)
		            q.pop();
		        
		        if(q.empty())
		            ans+="#";
		            
		       else
		            ans+=q.front();
		    }
		    
		    return ans;
}