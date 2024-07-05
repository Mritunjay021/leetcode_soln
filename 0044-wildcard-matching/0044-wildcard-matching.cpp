class Solution {
public:
    vector<vector<int>> dp;
    bool help(int i, int j, string& s, string& t) {
        if (i < 0 && j < 0)
            return true;
        else if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++)
                if (t[k] != '*')
                    return false;
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j] || t[j] == '?') {
            return dp[i][j] = help(i - 1, j - 1, s, t);
        } else if (t[j] == '*') {
            return dp[i][j] = help(i - 1, j, s, t) || help(i, j - 1, s, t);
        } else
            return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.resize(n, vector<int>(m, -1));
        return help(n-1, m-1, s, p);
    }
};