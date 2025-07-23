class Solution {
public:

    void func(int& c,int x,string ch,string& s)
    {
        stack<char> st;

        for(char it:s)
        {
            if(st.empty() || (it!=ch[0] && it!=ch[1]))
            st.push(it);
            else
            {
                if(it==ch[1] && st.top()==ch[0])
                {
                    c+=x;
                    st.pop();
                }
                else
                st.push(it);
            }
        }
        string temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(), temp.end());
    s = temp;
    }

    int maximumGain(string s, int x, int y) 
    {
        int c=0;

        if(x>y)
        {
            func(c,x,"ab",s);
            func(c,y,"ba",s);
        }
        else
        {
            func(c,y,"ba",s);
            func(c,x,"ab",s);
        }

        return c;

    }
};