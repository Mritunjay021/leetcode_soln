class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<int> id;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==key)
            id.push_back(i);
        }   

        set<int> st; 

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<id.size();j++)
            {
                if(abs(id[j]-i)<=k)
                st.insert((i));
            }
        }

        vector<int> v(st.begin(),st.end());

        return v;
    }
};