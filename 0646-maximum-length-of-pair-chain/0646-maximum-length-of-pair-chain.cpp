// class Solution {
// public:

//     int func(vector<vector<int>>& num,int i,int j)
//     {
//         if(i>=num.size() || j>=num.size())
//         return 0;

//         int np=func(num,i+1,j+1);

//         int p=INT_MIN;
        
//         if(num[i][1]<num[j][0])
//         p=max(1+func(num,i+1,j+1),func(num,i,j+1));
            
//         return max(p,np);
//     }

//     int findLongestChain(vector<vector<int>>& num) 
//     {
//         sort(num.begin(), num.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
//         return a[0] < b[0];  // Ascending order
//     });

//         return func(num,0,1)+1;
//     }
// };


class Solution { 
public:
    int func(vector<vector<int>>& num, int i, int prevEnd, vector<vector<int>>& memo) {
        if (i >= num.size()) return 0;

        if (memo[i][prevEnd + 1] != -1) return memo[i][prevEnd + 1];

        // Option 1: Skip the current pair
        int np = func(num, i + 1, prevEnd, memo);

        // Option 2: Include the current pair if it forms a chain
        int p = 0;
        if (prevEnd == -1 || num[prevEnd][1] < num[i][0]) {
            p = 1 + func(num, i + 1, i, memo);
        }

        return memo[i][prevEnd + 1] = max(p, np);
    }

    int findLongestChain(vector<vector<int>>& num) {
        sort(num.begin(), num.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        int n = num.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return func(num, 0, -1, memo);
    }
};
