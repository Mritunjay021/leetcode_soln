class Solution {
public:
    vector<vector<int>> re;
    void func(vector<int>& ls,vector<int>& ds,int i,int k,int n)
    {
        if(i>=9)
        return;
        if(ds.size()==k)
        {
            if(n==0)
            re.push_back(ds);
            return ;
        }
        if(ls[i]<=n)
        {
            ds.push_back(ls[i]);
            func(ls,ds,i+1,k,n-ls[i]);
            ds.pop_back();
            func(ls,ds,i+1,k,n);
        }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> ls={1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        func(ls,ds,0,k,n);
        return re;
    }
};