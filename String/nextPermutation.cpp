vector<int> nextPermutation(int N, vector<int> arr){
        
        int j = N-1;
        
        while(j>0 && arr[j]<arr[j-1])
            j--;
            
        if(j==0)
        {
            sort(arr.begin(),arr.end());
            return arr;
        }
        int diff=INT_MAX,index;
        for(int i=j;i<N;i++)
        {
            if(arr[i]-arr[j-1] < diff && arr[i]-arr[j-1]>0)
            {
                diff = arr[i]-arr[j-1];
                index = i;
            }
        }
        swap(arr[index],arr[j-1]);
        sort(arr.begin()+j,arr.end());
        return arr;
    }