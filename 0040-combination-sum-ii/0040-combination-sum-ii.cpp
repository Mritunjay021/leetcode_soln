class Solution {
public:
    
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) 
        {
            if(find(ans.begin(),ans.end(),ds)==ans.end())
            ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) 
      {
        ds.push_back(arr[ind]);
        findCombination(ind+1, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector < vector < int >> ans;
        vector < int > ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};