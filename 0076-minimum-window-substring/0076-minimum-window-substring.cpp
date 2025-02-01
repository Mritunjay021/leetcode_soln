class Solution {
public:
    string minWindow(string s, string t) 
    {
        int m = s.length();
        int n = t.length();

        int ar[256] = {0};  

        for (int i = 0; i < n; i++) 
            ar[t[i]]++;

        int l = 0, r = 0, k = 0;
        int mn = 1e9, sid = -1;

        while (r < m) 
        {
            if (ar[s[r]] > 0) 
                k++;
            
            ar[s[r]]--; 
            r++;  
            
            while (k == n) 
            {
                if (r - l < mn)  
                {
                    mn = r - l;
                    sid = l;
                }
                
                ar[s[l]]++;

                if (ar[s[l]] > 0) 
                    k--;

                l++;
            }
        }

        return sid == -1 ? "" : s.substr(sid, mn);
    }
};
