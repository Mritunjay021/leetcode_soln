class Solution {
public:
    int numTrees(int n) {
        vector<int> arr(n + 1, -1);
        return solve(n, arr);
    }

    int solve(int n, vector<int>& arr) {
        if (n <= 1) return 1;
        if (arr[n] != -1) return arr[n];

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solve(i - 1, arr) * solve(n - i, arr);
        }

        arr[n] = ans;
        return ans;
    }
};
