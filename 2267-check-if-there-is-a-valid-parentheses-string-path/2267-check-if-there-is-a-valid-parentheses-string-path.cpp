class Solution {
public:
    int m, n;

    bool func(vector<vector<char>>& grid, int i, int j, int balance,
              vector<vector<vector<int>>>& dp) {

        if (i >= m || j >= n)
            return false;

        // // Remaining cells cannot possibly close all '('
        // int remaining = (m - 1 - i) + (n - 1 - j);
        // if (balance > remaining + 1)
        //     return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = func(grid, i + 1, j, balance, dp);
        bool right = func(grid, i, j + 1, balance, dp);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even for a valid parentheses string
        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n, -1)));

        return func(grid, 0, 0, 0, dp);
    }
};
