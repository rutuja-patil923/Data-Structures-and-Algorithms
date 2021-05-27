// LRU implementation using queue
int pageFaults(int N, int C, int pages[]){
        
        queue<int> q;
        int page_faults=0;
        
        for(int i=0;i<N;i++)
        {
            //cout<<page_faults<<endl;
            if(!q.empty())
            {
                //cout<<"Entry 1"<<endl;
                bool flag=false;
                int last;
                //cout<<pages[i]<<" ";
                int size=q.size();
                for(int j=0;j<size;j++)
                {
                    int tmp=q.front();
                    //cout<<tmp<<" ";
                    q.pop();
                    //cout<<tmp;
                    if(tmp==pages[i])
                    {
                        flag=true;
                        last=tmp;
                        continue;
                    }
                    q.push(tmp);
                }
                //cout<<endl;
                //cout<<flag<<" ";
                if(flag)
                    q.push(last);
                if(!flag)
                {
                    //cout<<"*"<<endl;
                    if(q.size()==C)
                    {
                        q.pop();
                        q.push(pages[i]);
                    }
                    else
                        q.push(pages[i]);
                    page_faults++;
                }
                
            }
            else
            {
                //cout<<"Entry 2"<<endl;
                q.push(pages[i]);
                page_faults++;
            }
        }
        
        return page_faults;
    }