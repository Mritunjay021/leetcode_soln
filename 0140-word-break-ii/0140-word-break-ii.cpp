class Solution {
public:
    vector<vector<string>> ans;
    
    void func(string s, vector<string>& v, int j, vector<string>& re) 
    {
        if (j == s.length()) 
        {
            ans.push_back(re);
            return;
        }

        for (int i = 0; i < v.size(); i++) 
        {
            if (s.substr(j, v[i].length()) == v[i]) 
            {
                re.push_back(v[i]);
                func(s, v, j + v[i].length(), re);
                re.pop_back(); 
            }
        }
    }


    vector<string> wordBreak(string s, vector<string>& v) 
    {
        vector<int> dp(s.length()+1,-1);
        vector<string> re;
        func(s, v, 0, re); 
        string st;
        for (auto& words : ans) 
        {
            string temp = "";
            for (int i = 0; i < words.size(); i++) 
            {
                temp += words[i]; 
                if (i < words.size() - 1) 
                    temp += " "; 
            }
            re.push_back(temp); 
        }
        return re;  
    }
};