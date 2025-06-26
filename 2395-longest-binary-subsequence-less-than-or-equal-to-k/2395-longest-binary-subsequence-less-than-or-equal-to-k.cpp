class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int n = s.length();
        int mx = 0;
        long long v = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
                mx++;
            else
            {
                if(n - 1 - i < 32) 
                {
                    long long ad = 1LL << (n - 1 - i);
                    if(v + ad <= k)
                    {
                        v += ad;
                        mx++;
                    }
                }
            }
        } 
        return mx;
    }
};
