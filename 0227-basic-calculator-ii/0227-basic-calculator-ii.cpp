class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;

        char ch='+';
        int nm=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            nm=nm*10+(s[i]-'0');
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1)
            {
                if(ch=='+')
                st.push(nm);
                else if(ch=='-')
                st.push(-1*nm);
                else if(ch=='*')
                {
                    int el=st.top()*nm;
                    st.pop();
                    st.push(el);
                }
                else if(ch=='/')
                {
                    int el=st.top()/nm;
                    st.pop();
                    st.push(el);
                }
                nm=0;
                ch=s[i];
            }
        }
        int re=0;

        while(!st.empty())
        {
            re+=st.top();
            cout<<re<<endl;
            st.pop();
        }

        return re;
    }
};