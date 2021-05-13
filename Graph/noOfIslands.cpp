public:
    int vis[505][505];
    int dx[8]={-1,0,1,0,-1,-1,1,1};
    int dy[8]={0,1,0,-1,-1,1,-1,1};
    int N , M ;
    
    bool isValid(int x,int y)
    {
        if(x>=0 && y>=0 && x<M && y <N && vis[x][y]==0)
            return true;
        return false;
    }
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
        vis[x][y]=1;
        
        for(int i=0;i<8;i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX,newY) && grid[newX][newY]=='1')
                dfs(newX,newY,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        memset(vis,0,sizeof(vis));
        int components=0;
        N = grid[0].size();
        M = grid.size();
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    components++;
                }
                
            }
        }
        
        return components;
    }