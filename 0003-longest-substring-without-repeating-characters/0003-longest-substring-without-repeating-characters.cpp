class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map <int,int>mpp;
      int l = 0, r = 0;
      int n = s.size();
      int len = 0;
      while (r < n) 
      {
        mpp[s[r]]++;
        if(mpp[s[r]]>1)
        {
            while(mpp[s[r]]>1)
            {
                mpp[s[l]]--;
                l++;
            }
        }
        len = max(len, r - l + 1);
        r++;
      }
      return len;
    }
};