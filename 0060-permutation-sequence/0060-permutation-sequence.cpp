class Solution {
public:

    string getPermutation(int n, int k) 
    {
        vector<int> v;
        int f=1;
        for(int i=1;i<=n;i++)
        {
            f*=i;
            v.push_back(i);
        }
        f/=n;
        k--;

        string s="";
        while(!v.empty())
        {
            int id=(k)/f;
            k=k%f;
            s=s+to_string(v[id]);
            v.erase(v.begin()+id);

            if(!v.empty())
            f/=v.size();
        }
        return s;
    }
};