class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int> mp;
        int n=nums1.size();

        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]++;
            mp[nums2[i]]--;
        }

        int re=0;

        for(auto &p:mp)
        {
            int f=p.first;
            int s=p.second;

            if(s%2 != 0)
            return -1;

            if(s>0)
            re+=s/2;
        }
        return re;

    }
};