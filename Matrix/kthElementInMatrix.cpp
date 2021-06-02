int kthSmallest(int mat[MAX][MAX], int n, int k)
{
     
    int col[n];
     
    for(int i=0;i<n;i++)
        col[i]=0;
    int ans;
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cout<<mat[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=0;i<k;i++)
    {
        int smallest_row,minimum=INT_MAX;
        
        for(int j=0;j<n;j++)
        {
            if(col[j]<n && mat[j][col[j]] < minimum)
            {
                smallest_row = j;
                minimum = mat[j][col[j]];
            }
        }
        
        col[smallest_row]++;
        ans = minimum;
        //cout<<smallest_row<<" "<<endl;
        //cout<<minimum<<" ";
    }
    
    return ans;
      
}