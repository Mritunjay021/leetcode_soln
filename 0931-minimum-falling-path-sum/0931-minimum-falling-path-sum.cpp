// class Solution {
// public:

//     int func(vector<vector<int>>& m,int i,int j,vector<vector<int>>& dp)
//     {
        
//         if(j>=m.size() || j<0)
//         return 1e9;

//         else if(i==m.size()-1)
//         return m[i][j];

//         else if(dp[i][j]!=-1)
//         return dp[i][j];

//         int s1=m[i][j]+func(m,i+1,j,dp);
//         int s2=m[i][j]+func(m,i+1,j+1,dp);
//         int s3=m[i][j]+func(m,i+1,j-1,dp);
//         return dp[i][j]=min(s1,min(s2,s3));
//     }

//     int minFallingPathSum(vector<vector<int>>& m) 
//     {
//         int mn=1e9;
//         vector<vector<int>> dp(m.size(),vector<int>(m.size(),-1));
//         for(int c=0;c<m.size();c++)
//         {
//             int val=func(m,0,c,dp);
//             mn=min(mn,val);
//         }    
//         return mn;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize dp array with the first row values
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }
        
        // Build the dp array from the second row to the last row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j] + dp[i-1][j]; // Directly from above
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i-1][j-1]); // From above left
                }
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i-1][j+1]); // From above right
                }
            }
        }
        
        // Find the minimum value in the last row of dp array
        int minPathSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minPathSum = min(minPathSum, dp[n-1][j]);
        }
        
        return minPathSum;
    }
};
