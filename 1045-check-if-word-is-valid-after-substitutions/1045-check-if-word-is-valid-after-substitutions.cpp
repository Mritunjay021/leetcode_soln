class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        int a=0,b=0,c=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='c')
            st.push(s[i]);
            else
            {
                if(st.size()>=2)
                {
                    if(st.top()=='b')
                    st.pop();
                    else
                    return false;

                    if(st.top()=='a')
                    st.pop();
                    else
                    return false;
                }
            }
        }    
        return st.empty();
    }
};