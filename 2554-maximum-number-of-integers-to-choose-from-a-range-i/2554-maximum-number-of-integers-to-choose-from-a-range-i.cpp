class Solution {
public:
    int maxCount(vector<int>& banned, int n, int mx) 
    {
        set<int> st(banned.begin(),banned.end());
        int sum=0,c=0;
          

        for(int i=1;i<=n;i++)
        {
            if(st.find(i)==st.end() && sum+i<=mx)
            {
                sum+=i;
                c++;
            }
        }
        return c;
    }
};