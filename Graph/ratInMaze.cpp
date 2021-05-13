vector<string> ans;
    bool isValid(int x,int y,int n,vector<vector<int>> &m)
    {
        if(x<0 || y<0 || x>=n || y>=n || m[x][y]==0)
            return false;
        return true;
    }
    void solve(int x,int y,vector<vector<int>> vis,vector<vector<int>> &m,string res,int n)
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(res);
            return;
        }
        vis[x][y]=1;
        string op=res;
        if(isValid(x-1,y,n,m) && vis[x-1][y]==0)
        {
            op += "U";
            solve(x-1,y,vis,m,op,n);
            op=res;
        }
        if(isValid(x+1,y,n,m) && vis[x+1][y]==0)
        {
            op += "D";
            solve(x+1,y,vis,m,op,n);
            op=res;
        }
        if(isValid(x,y-1,n,m) && vis[x][y-1]==0)
        {
            op += "L";
            solve(x,y-1,vis,m,op,n);
            op=res;
        }
        if(isValid(x,y+1,n,m) && vis[x][y+1]==0)
        {
            op += "R";
            solve(x,y+1,vis,m,op,n);
            op=res;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        ans.clear();
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==0)
            return ans;
        string res="";   
        solve(0,0,vis,m,res,n);
        sort(ans.begin(),ans.end());
        return ans;
    }