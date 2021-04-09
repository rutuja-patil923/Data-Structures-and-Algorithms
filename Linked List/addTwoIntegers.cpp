    // Question Link : https://leetcode.com/problems/add-two-numbers-ii/



    int length(ListNode* head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int lenL1=length(l1);
        int lenL2=length(l2);
        int p = max(lenL1,lenL2);
        if(lenL1<lenL2)
        {
            swap(lenL1,lenL2);
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }
        
        ListNode* ans=NULL,*ans_head=NULL;
        ListNode*carry=NULL,*carry_head=NULL;
        bool carry_till_now=false;
        ListNode* dig1=l1;
        ListNode* dig2=(lenL1==lenL2)?l2:new ListNode(0);
        
        while(p)
        {
            p-=1;
            int temp=(dig1->val+dig2->val)%10;
            int carr=(dig1->val+dig2->val)/10;
            ListNode* newNode=new ListNode(temp);
            
            if(carr)
                carry_till_now=true;
            
            if(!ans)
            {
                ans=newNode;
                ans_head=newNode;
            }
            else
                ans->next=newNode;
            ans=newNode;
            
            
            if(carry_till_now)
            {
                ListNode* newCarry=new ListNode(carr);
                if(!carry)
                {
                    carry=newCarry;
                    carry_head=newCarry;
                }
                else
                    carry->next=newCarry;
                carry=newCarry;
            }
            
            if(p==lenL2)
                dig2=l2;
            else
                dig2=(p>lenL2)?new ListNode(0):dig2->next;
            dig1=dig1->next;
        }
        
        if(carry_till_now)
        {
            ListNode* newCarry=new ListNode(0);
            carry->next=newCarry;
            return addTwoNumbers(ans_head,carry_head);
        }
        
        return ans_head;
    }