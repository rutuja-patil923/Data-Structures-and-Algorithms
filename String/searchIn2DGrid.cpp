bool isValid(vector<vector<char>>grid, string word,int index,int i,int j,int N,int M,string direction)
    {
        if(index==word.length())
            return true;
        if(i<0 || j<0 || i>=N || j>=M || grid[i][j]!=word[index])
            return false;
        bool res;
        if(direction=="UDL")
        {
        	res = isValid(grid,word,index+1,i-1,j-1,N,M,"UDL");
        	return res;
        }
        if(direction=="U")
        {
        	res = isValid(grid,word,index+1,i-1,j,N,M,"U");
        	return res;
        }
        if(direction=="UDR")
        {
        	res = isValid(grid,word,index+1,i-1,j+1,N,M,"UDR");
        	return res;
        }
        if(direction=="R")
        {
        	res = isValid(grid,word,index+1,i,j+1,N,M,"R");
        	return res;
        }
        if(direction=="DDR")
        {
        	res = isValid(grid,word,index+1,i+1,j+1,N,M,"DDR");
        	return res;
        }
        if(direction=="D")
        {
        	res = isValid(grid,word,index+1,i+1,j,N,M,"D");
        	return res;
        }
        if(direction=="DDL")
        {
        	res = isValid(grid,word,index+1,i+1,j-1,N,M,"DDL");
        	return res;
        }
        if(direction=="L")
        {
        	res = isValid(grid,word,index+1,i,j-1,N,M,"L");
        	return res;
        }
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    int N = grid.size();
	    int M = grid[0].size();
	    
	    vector<vector<int>> ans;
	    //cout<<N<<M;
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<M;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	            	bool flag= isValid(grid,word,1,i-1,j-1,N,M,"UDL") ||
	            			   isValid(grid,word,1,i-1,j,N,M,"U") ||
	            			   isValid(grid,word,1,i-1,j+1,N,M,"UDR") ||
	            			   isValid(grid,word,1,i,j+1,N,M,"R") ||
	            			   isValid(grid,word,1,i+1,j+1,N,M,"DDR") ||
	            			   isValid(grid,word,1,i+1,j,N,M,"D") ||
	            			   isValid(grid,word,1,i+1,j-1,N,M,"DDL") ||
	            			   isValid(grid,word,1,i,j-1,N,M,"L");
	              	if(flag)
	              		ans.push_back({i,j});
	            }
	        }
	    }
	    
	    return ans;
	}