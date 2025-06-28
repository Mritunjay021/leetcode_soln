class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n=nums.size();

        if(n==k)
        return nums;

        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nq;
        vector<int> re;

        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        while(k--)
        {
            auto it=pq.top();
            pq.pop();
            nq.push({it.second,it.first});
        }

        while(!nq.empty())
        {
            auto it=nq.top();
            nq.pop();
            re.push_back(it.second);
        }

        return re;
    }
};