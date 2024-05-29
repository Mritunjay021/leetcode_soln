class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;
        int f=1;
        if(s.length()%2!=0)
        return false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.empty() || st.top()!='(')
                {
                    f=0;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if(s[i]=='}')
            {
                if(st.empty() || st.top()!='{')
                {
                    f=0;
                    break;
                }
                else
                {
                    st.pop();
                    //f=1;
                }
            }
            else if(s[i]==']')
            {
                if(st.empty() || st.top()!='[' )
                {
                    f=0;
                    break;
                }
                else
                {
                    st.pop();
                    //f=1;
                }
            }
        }
        if(st.empty())
        return f;   
        else 
        return false;
    }
};