class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        int n=arr.size();
        set<int> st,pv;

        for(int i=0;i<n;i++)  
        {
            set<int> cr;
            for(auto it:pv)
            {
                if(cr.find(arr[i]|it)==cr.end())
                cr.insert(arr[i]|it);
            }

            if(cr.find(arr[i])==cr.end())
            cr.insert(arr[i]);

            st.insert(cr.begin(),cr.end());
            pv.clear();
            pv.insert(cr.begin(),cr.end());            
        }  

        return st.size();
    }
};