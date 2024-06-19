class Solution {

public:
    void help(int ind, int sum, int k, vector<vector<int>>& ans, vector<int>& v, int a[]) {
            if (sum == 0 && v.size() == k)
            {
                ans.push_back(v);
            return;
        }
        else if(ind>=9)
        return ;
        if (a[ind] <= sum) {
            v.push_back(a[ind]);
            help(ind + 1, sum - a[ind], k, ans, v, a);
            v.pop_back();  
        }
        help(ind + 1, sum, k, ans, v, a);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        help(0, n, k, ans, v, a);
        return ans;
    }
};