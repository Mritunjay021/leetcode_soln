class Solution {
public:
    vector<string> partitionString(string s) 
    {
        vector<string> v;
        set<string> st;
        string re="";

        for(char c:s)
        {
            re+=c;
            if(st.find(re)==st.end())
            {
                v.push_back(re);
                st.insert(re);
                re="";
            }
        } 

        return v;   
    }
};