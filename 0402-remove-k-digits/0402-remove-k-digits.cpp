class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int l=num.length();
        if(l==k)
        return "0";

        string st;

        for(int i=0;i<l;i++)
        {
            while(!st.empty() && k && num[i]<st.back())
            {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        while (k && !st.empty()) 
        {
            st.pop_back();
            k--;
        }

        
        int i=0;
        while (i < st.size() && st[i] == '0')
        i++;

        return (i == st.size()) ? "0" : st.substr(i);

            
    }
};