class Solution {
public:

    int func(vector<int>& v, int k, int m) 
    {
        long long re = 0, c = 0;
        for (int i = 0; i < v.size(); i++) 
        {
            if (v[i] <= m) 
            {
                c++;
                if (c == k) 
                {
                    re++;
                    c = 0;
                }
            } 
            else 
            {
                c = 0;
            }
        }
        return re;
    }

    int minDays(vector<int>& v, int md, int k) 
    {
        int l = *min_element(v.begin(), v.end());
        int u = *max_element(v.begin(), v.end());
        
        if (md * 1LL * k > v.size()) 
            return -1;

        int ans = -1;
        while (l <= u) 
        {
            int m = (l + u) / 2; 
            int re = func(v, k, m);
            if (re >= md) 
            {
                ans = m; 
                u = m - 1; 
            } 
            else 
            {
                l = m + 1; 
            }
        }
        return ans;
    }
};
