class Solution {
public:
    int dfs(map<int, vector<int>>& mp, vector<int>& it, int id) {
        int maxTime = 0;
        for (int sub : mp[id]) {
            maxTime = max(maxTime, dfs(mp, it, sub));
        }
        return maxTime + it[id];
    }

    int numOfMinutes(int n, int hd, vector<int>& mn, vector<int>& it) {
        map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            if (mn[i] != -1) {
                mp[mn[i]].push_back(i);
            }
        }
        
        return dfs(mp, it, hd);
    }
};
