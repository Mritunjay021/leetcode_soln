class Solution {
public:

    int re=INT_MAX;
    int n;

    void func(vector<int> cookies,int k,int i,vector<int>& arr)
    {
        if(i >= cookies.size() )
        {
            int mx=*max_element(begin(arr),end(arr));
            re=min(re,mx);
            return ;
        }

        for(int j=0;j<k;j++)
        {
            arr[j]+=cookies[i];

            if(arr[j]<re)
            func(cookies,k,i+1,arr);

            arr[j]-=cookies[i];

            if(arr[j]==0)
            break;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) 
    {
        n=cookies.size();

        vector<int> arr(k,0);
        
        func(cookies,k,0,arr);
        
        return re;
    }
};