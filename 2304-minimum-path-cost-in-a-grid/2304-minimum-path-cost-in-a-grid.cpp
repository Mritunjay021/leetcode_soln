// class Solution {
// public:

//     int func(vector<vector<int>>& grid, vector<vector<int>>& moveCost,
//     int i,int j,vector<vector<int>>& dp)
//     {
//         if(i==grid.size()-1)
//         return grid[i][j];
//         // if(j==grid[0].size())
//         // return 0;
//         if(dp[i][j]!=-1)
//         return dp[i][j];
//         int mn=INT_MAX;
//         for(int k=j;k<grid[0].size();k++)
//         mn=min(grid[i][k]+moveCost[i][k]+func(grid,moveCost,i+1,k,dp),mn);
//         return dp[i][j]=mn;
//     }

//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
//     {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         int re=INT_MAX;
//         for(int i=0;i<m;i++)
//         {
//             re=min(re,func(grid,moveCost,0,i,dp));
//         }
//         return re;

//     }
// };


class Solution {
public:

    int func(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j, vector<vector<int>>& dp) {
        // Base case: if at the last row, return the value of the current cell
        if (i == grid.size() - 1) {
            return grid[i][j];
        }
        
        // Memoization: if result is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int mn = INT_MAX;
        
        // Iterate over all columns in the next row (starting from 0, not j)
        for (int k = 0; k < grid[0].size(); k++) {
            // Get the grid value at the current position
            int currentValue = grid[i][j];
            // Get the cost to move from this cell to column k of the next row
            int moveCostValue = moveCost[currentValue][k];
            // Calculate the total cost recursively
            mn = min(mn, grid[i][j] + moveCostValue + func(grid, moveCost, i + 1, k, dp));
        }
        
        // Store the result in dp and return it
        return dp[i][j] = mn;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        // Initialize dp array with -1 for memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int result = INT_MAX;
        
        // Start the recursion from every cell in the first row and take the minimum result
        for (int j = 0; j < m; j++) {
            result = min(result, func(grid, moveCost, 0, j, dp));
        }
        
        return result;
    }
};
