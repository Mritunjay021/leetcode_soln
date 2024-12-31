class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> res(n, 0);  

        int p = 0;  
        int m = 1;  

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res[p] = nums[i];  
                p += 2; 
            } else {
                res[m] = nums[i];  
                m += 2;  
            }
        }
        return res;
    }
};