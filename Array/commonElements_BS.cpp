bool findElement(int A[],int N,int key)
       {
           int low = 0 , high = N-1;
           
           while(low <= high)
           {
               int mid = (low + high)/2;
               if(A[mid]==key)
                    return true;
               if(A[mid]<key)
                    low = mid+1;
                else
                    high =mid-1;
           }
           return false;
       }
       vector<int> solve(int A[],int n1,int B[],int n2,int C[],int n3)
       {
           set<int> res;
           for(int i=0;i<n1;i++)
           {
               int check = A[i];
               
               
               if(findElement(B,n2,check) && findElement(C,n3,check))
                    res.insert(check);
           }
           vector<int> arr;
           arr.assign(res.begin(),res.end());
           return arr;
       }
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            
            vector<int> ans;
            if(n1<=n2 && n1<=n3) 
                ans = solve(A,n1,B,n2,C,n3);
            else if(n2<=n1 && n2<=n3)
                ans = solve(B,n2,A,n1,C,n3);
            else if(n3<=n1 && n3<=n2)
                ans = solve(C,n3,A,n1,B,n2);
                
            return ans;
        }