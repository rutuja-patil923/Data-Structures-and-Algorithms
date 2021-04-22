queue<int> modifyQueue(queue<int> q, int k)
{
    
    stack<int> st;
    queue<int> qe;
    int size=q.size();

    for(int i=0;i<size;i++)
    {
        if(i<k)
            st.push(q.front());
        else
            qe.push(q.front());
        q.pop();
    }
    //cout<<st.size()<<" "<<qe.size()<<endl;
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while(!qe.empty())
    {
        q.push(qe.front());
        qe.pop();
    }
    
    return q;
}