class Solution {
public:
    string removeOuterParentheses(string s)
    {
        int c=0;
        string ns="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            c++;
            else
            {
                c--;
                if(c>=1)
                ns+=")";
                continue;
            }
            if(c>1)
            ns+="(";

        }    
        return ns;
    }
};