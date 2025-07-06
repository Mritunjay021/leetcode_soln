class FindSumPairs {
public:

    vector<int> n1,n2;
    unordered_map<int,int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        n1=nums1;
        n2=nums2;  

        for(int x:n2)
        mp[x]++;  
    }
    
    void add(int i, int val) 
    {
        mp[n2[i]]--;
        n2[i]+=val;
        mp[n2[i]]++;
    }
    
    int count(int tot) 
    {
        int c=0;
        for(int x:n1)
        {
            c+=mp[tot-x];
        }

        return c;

    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */