bool check(int num,int n)
        {
            int count=0,power=5;
            
            while(num/power != 0)
            {
                count += num/power;
                power *= 5;
            }
            
            return count>=n ;
        }
        int findNum(int n)
        {
            if(n==1)
                return 5;
            int low=0,high=5*n;
            
            while(low<high)
            {
                int mid = (high+low)/2;
                
                if(check(mid,n))
                    high = mid;
                else
                    low = mid + 1;
                
            }
            return low;
            
        }