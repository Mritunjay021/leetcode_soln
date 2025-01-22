class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;

        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mx) {
                right = i;
            }
            mx = max(mx, nums[i]);
        }

        int mn = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > mn) {
                left = i;
            }
            mn = min(mn, nums[i]);
        }

        return (right == -1) ? 0 : (right - left + 1);
    }
};
