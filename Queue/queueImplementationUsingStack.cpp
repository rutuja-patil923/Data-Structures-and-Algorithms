
void StackQueue :: push(int x)
{
    if(s1.empty())
        s1.push(x);
    else
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty())
        return -1;
    int store=s1.top();
    s1.pop();
    return store;
}