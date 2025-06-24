class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int n=nums.size();
        vector<int> id;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
            id.push_back(i);
        }   

        set<int> st;

        for(int j=0;j<id.size();j++)
        {
            int l=0,h=n-1;
            if(id[j]>k)
            l=id[j]-k;

            if(id[j]+k<n)
            h=id[j]+k;

            for(int i=l;i<=h;i++)
            st.insert(i);

        }

        vector<int> v(st.begin(),st.end());

        return v;
    }
};