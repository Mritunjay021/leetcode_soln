class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& grp) 
    {
        int n=grp.size();
        int l=-1;
        vector<string> st;

        for(int i=0;i<n;i++)
        {
            if(grp[i]!=l)
            {
                st.push_back(words[i]);
                l=grp[i];
            }
        }    

        return st;
    }
};