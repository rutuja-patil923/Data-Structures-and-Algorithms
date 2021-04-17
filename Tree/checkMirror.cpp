    bool solve(vector<stack<int>> tree1,vector<queue<int>> tree2)
    {
        
        for(int i=0;i<tree1.size();i++)
        {
            stack<int> st=tree1[i];
            queue<int> q=tree2[i];
            
            while(!st.empty() && !q.empty())
            {
                //cout<<i<<endl;
                int top=st.top();
                int front=q.front();
                //cout<<top<<" "<<front<<endl;
                
                if(top!=front)
                    return false;
                    
                st.pop();
                q.pop();
            }
            
            if(!st.empty() || !q.empty())
                return false;
        }
        
        return true;
    }
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        
        vector<stack<int>> tree1(n+1);
        vector<queue<int>> tree2(n+1);
        
        for(int i=0;i<e*2;i+=2)
            tree1[A[i]].push(A[i+1]);
            
        for(int i=0;i<e*2;i+=2)
            tree2[B[i]].push(B[i+1]);
            
        return solve(tree1,tree2);
    }