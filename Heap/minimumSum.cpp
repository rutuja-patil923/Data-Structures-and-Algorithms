string solve(int arr[], int n) 
{
        
    sort(arr,arr+n,greater<int>());
        
    int carry=0;
    string ans="";
        
    for(int i=0;i+1<n;i+=2)
    {
        int sum = arr[i] + arr[i+1] + carry;
            
        carry = sum/10;
        sum = sum %10;
            
        ans = to_string(sum) + ans;
    }
        
    if(n%2)
        ans = to_string(carry + arr[n-1]) + ans;
    else
        ans = to_string(carry) + ans;
            
    int pos;
            
    for(int i=0;i<ans.length();i++)
    {
        if(ans[i]=='0')
            continue;
        else
        {
            pos = i;
            break;
        }
    }
    string res="";
    for(int i=pos;i<ans.length();i++)
        res += ans[i];
    return res;
}