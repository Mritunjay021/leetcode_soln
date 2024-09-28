// class Solution {
// public:

//     int func(int n,int i,vector<int>& dp)
//     {
//         if(i>n)
//         return 1e9;
//         if(dp[i]!=-1)
//         return dp[i];
//         else if(i==n)
//         return dp[n];
//         return 1+min(func(n,i+3,dp),func(n,i+2,dp));
//     }

//     int minimumRounds(vector<int>& tasks) 
//     {
//         int n=tasks.size();
//         unordered_map<int, int> ar;
        
//         for (int task : tasks) {
//             ar[task]++;
//         }
        
//         int k=0;
//         for (int i=0;i<ar.size();i++)
//         {
//             vector<int> dp(ar[i]->second,-1);
//             int x=func(ar[i]->second,0,dp);
//             if(x>=1e9)
//             return -1;
//             k+=x;
//         }
//         return k;
//     }
// };

#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int func(int n, int i, std::vector<int>& dp) {
        if (i > n) return 1e9;  // Return a large number for invalid cases
        if (dp[i] != -1) return dp[i];
        if (i == n) return dp[n] = 0;  // Base case: no more rounds required if all tasks are done
        
        dp[i] = 1 + std::min(func(n, i + 2, dp), func(n, i + 3, dp));
        return dp[i];
    }

    int minimumRounds(std::vector<int>& tasks) {
        std::unordered_map<int, int> taskCount;

        // Count occurrences of each task difficulty
        for (int task : tasks) {
            taskCount[task]++;
        }

        int totalRounds = 0;

        // Iterate through the unordered_map to process each difficulty level
        for (auto& pair : taskCount) {
            int count = pair.second;

            // If there's only 1 task of a certain difficulty, it's impossible to finish
            if (count == 1) {
                return -1;
            }

            // Create a dp array for each difficulty level
            std::vector<int> dp(count + 1, -1);
            int rounds = func(count, 0, dp);
            
            if (rounds >= 1e9) return -1;  // Impossible case
            totalRounds += rounds;
        }

        return totalRounds;
    }
};
