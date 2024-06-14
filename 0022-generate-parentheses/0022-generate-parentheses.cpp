class Solution {
public:

    void func(int n,int o,int c,vector<string>& v,string s)
    {
        if(n==o && n==c)
        v.push_back(s);
        if(o<n)
        {
            func(n,o+1,c,v,s+'(');
        }
        if(c<o)
        {
            func(n,o,c+1,v,s+')');
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> v;
        func(n,0,0,v,"");
        return v;
    }
};