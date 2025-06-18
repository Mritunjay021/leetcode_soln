class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& lst) 
    {
        queue<pair<string,int>> q;  

        unordered_set<string> st(lst.begin(),lst.end());

        if(st.find(ew)==st.end())
        return 0;

        q.push({bw,1}); 
        st.erase(bw);

        while(!q.empty())
        {
            string w=q.front().first;
            int mv=q.front().second;

            q.pop();

            if(w==ew)
            return mv;

            for(int i=0;i<w.length();i++)
            {
                string wd=w;
                for(char c='a';c<='z';c++)
                {
                    wd[i]=c;
                    if(st.find(wd)!=st.end())
                    {
                        q.push({wd,mv+1});
                        st.erase(wd);
                    }
                }
            }
        } 
        return 0;
    }
};