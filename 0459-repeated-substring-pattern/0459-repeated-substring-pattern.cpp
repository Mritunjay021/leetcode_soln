class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.length();
        vector<int> lps(n, 0);

        int i = 1, l = 0;
        while (i < n)
        {
            if (s[i] == s[l]) {
                l++;
                lps[i] = l;
                i++;
            } else {
                if (l == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    l = lps[l - 1];
                }
            }
        }

        int pl = lps[n - 1];
        if (pl > 0 && n % (n - pl) == 0) {
            return true;
        }
        return false;
    }
};
