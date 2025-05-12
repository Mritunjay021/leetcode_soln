class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& dig) 
    {
        sort(dig.begin(),dig.end());

        set<int> st;
        int n=dig.size();

        for(int i=0;i<n;i++)
        {
            if(dig[i]==0)
            continue;

            for(int j=0;j<n;j++)
            {
                if(j==i)
                continue;

                for(int k=0;k<n;k++)
                {
                    if(i==k || j==k)
                    continue;

                    if(dig[k]%2==0)
                    {
                        st.insert((dig[i]*100+dig[j]*10+dig[k]));
                    }
                }
            }
            
        }  

        vector<int> re{st.begin(),st.end()};  

        return re;
    }
};