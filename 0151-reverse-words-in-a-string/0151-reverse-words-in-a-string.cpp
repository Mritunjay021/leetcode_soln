class Solution {
public:
    string reverseWords(string s) 
    {
        s=" "+s+" ";
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            st.push(i);
        }
        string ns="";
        while(!st.empty())
        {
            int c=st.top(); 
            st.pop();
            if(c>0 && c-st.top()>1)
            {
                ns+=s.substr(st.top()+1,c-st.top()-1)+" ";
            }
        }
        int l=0,t=0,i=0,c=0;
        while(ns[i]==' ')
        {
            i++;
        }
        ns.erase(0,i);
        for(i=ns.length()-1;i>=0;i--)
        {
            if(ns[i]!=' ')
            break;
            c++;
        }
        ns.erase(i,c-1);
        ns=ns.substr(0,ns.length()-1);
        return ns;
    }
};