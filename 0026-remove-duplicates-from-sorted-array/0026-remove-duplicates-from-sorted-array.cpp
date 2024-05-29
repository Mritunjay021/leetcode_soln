class Solution {
public:
    int search(vector<int> nums, int beg) {
        if (beg == nums.size() - 1 || nums[beg] < nums[beg + 1])
            return beg + 1;

        int i = beg, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] > nums[i] && nums[mid - 1] == nums[i])
                return mid;
            else if (nums[mid] == nums[i] &&
                     (mid + 1 == nums.size() || nums[mid + 1] > nums[i]))
                return mid + 1;
            else if (nums[mid] > nums[i])
                j = mid - 1;
            else
                i = mid + 1;
        }
        return 0;
    }

    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        int n = 0, c = 0;
        for (int i = 0; i < l; i = n) {
            n = search(nums, i);
            nums[c] = nums[i];
            c++;
        }
        return c;
    }
};