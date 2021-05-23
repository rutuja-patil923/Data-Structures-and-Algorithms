    public:
    string smallestNumber(int S, int D)
    {
       
       int sum=0;
       
       string ans="";
       for(int i=0;i<D-1;i++)
       {
          for(int j=9;j>=0;j--)
          {
              if(S-j>0)
              {
                  ans += (j+'0');
                  S -= j;
                  break;
              }
          }
       }
       if(S>9)
            return "-1";
       ans += (S+'0');
       
       reverse(ans.begin(),ans.end());
       return ans;
    }