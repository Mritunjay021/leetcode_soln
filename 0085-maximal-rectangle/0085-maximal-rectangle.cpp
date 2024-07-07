class Solution {
public:

    int func(vector<int>& ar) 
    {
        int n=ar.size();
        stack<int> st;
        int ls[n],rs[n];
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && ar[st.top()]>=ar[i])
            st.pop();
            if(st.empty())
            ls[i]=0;
            else
            ls[i]=st.top()+1;
            st.push(i);
        }    
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && ar[st.top()]>=ar[i])
            st.pop();
            if(st.empty())
            rs[i]=n-1;
            else
            rs[i]=st.top()-1;
            st.push(i);

        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,(rs[i]-ls[i]+1)*ar[i]);
        }
        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int r=matrix.size();
        int c=matrix[0].size();
        int mx=0;
        vector<int> ht(c,0);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]=='1')
                ht[j]++;
                else
                ht[j]=0;
            }
            int re=func(ht);
            mx=max(re,mx);
        }
        return mx;
    }
};