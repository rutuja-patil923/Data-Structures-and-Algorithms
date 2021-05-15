		vector<string> ans;
	    void printAllPermutations(int index,string op,int N)
	    {
	        if(index==N)
	        {
	            ans.push_back(op);
	            return;
	        }
	        
	        for(int i=index;i<=N;i++)
	        {
	            string temp=op;
	            swap(temp[index],temp[i]);
	            printAllPermutations(index+1,temp,N);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    printAllPermutations(0,S,S.length()-1);
		    sort(ans.begin(),ans.end());
		    return ans;
		}