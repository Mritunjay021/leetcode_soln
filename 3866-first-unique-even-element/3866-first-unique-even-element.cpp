class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int re = -1;
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> mp(mx+1, 0);

        for (auto it : nums) {
            if (it % 2)
                continue;
            else
                mp[it]++;
        }

        for (auto it : nums) {
            if(mp[it]==1)
            {
                re=it;
                break;
            }
        }

        return re;
    }
};