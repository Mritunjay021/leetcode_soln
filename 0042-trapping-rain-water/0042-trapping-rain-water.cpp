class Solution {
public:
    int trap(vector<int>& ht) 
    {
        stack<int> st;
        int c=0;

        for(int i=0;i<ht.size();i++)
        {
            if(st.empty() && ht[i]==0)
            continue;

            while(!st.empty() && ht[i]>=ht[st.top()])
            {
                int top=st.top();
                st.pop();

                if(st.empty())
                break;

                int d=i-st.top()-1;
                int bw=min(ht[i],ht[st.top()])-ht[top];

                c+=d*bw;

            }
            st.push(i);
        }    
        return c;
    }
};