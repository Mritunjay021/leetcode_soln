class Solution {
public:
    vector<int> closestPrimes(int l, int r) 
    {
        vector<int> v;

        if (l <= 2 && r >= 2) v.push_back(2);
        if (l <= 3 && r >= 3) v.push_back(3);

        for(int i=max(l,2);i<=r;i++)
        {
            if(i%2==0 || i%3==0)
            continue;
            bool ip=1;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    ip=0;
                    break;
                }
            }
            if(ip)
            v.push_back(i);
        }  

        if(v.size()<2)
        return {-1,-1};  

        vector<int> res={-1,-1};
        int mn=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            cout<<v[i]<<endl;
            if(mn>(v[i]-v[i-1]))
            {
                mn=v[i]-v[i-1];
                res ={v[i-1],v[i]};
            }
        }

        return res;
    }
};