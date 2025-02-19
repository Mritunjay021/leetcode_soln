class Solution {
public:
    string makeLargestSpecial(string s) 
    {
        vector<string> res;
        int i=0,c=0;

        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='1')
            c++;
            else
            c--;

            if(c==0)
            {
                res.push_back('1'+makeLargestSpecial(s.substr(i+1,j-i-1))+'0');
                i=j+1;
            }
        }    
        sort(res.begin(), res.end(), greater<string>());
        string res2="";

        for(int k=0;k<res.size();k++)
        res2+=res[k];

        return res2;
    }
};