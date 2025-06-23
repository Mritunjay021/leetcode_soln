class Solution {
public:
    int minimumDeletions(string word, int k) 
    {
        vector<int> arr(26,0);
        for(char c:word)
        arr[c-'a']++;
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + arr[i];
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int cnt = (i > 0) ? pre[i - 1] : 0;

            auto it = upper_bound(arr.begin(), arr.end(), arr[i] + k);
            int idx = it - arr.begin();

            int y = pre[n - 1] - ((idx > 0) ? pre[idx - 1] : 0);
            int l = n - idx;
            l = l * (arr[i] + k);
            y -= l;
            cnt += y;

            ans = min(ans, cnt);
        }
        return ans;
    }
};