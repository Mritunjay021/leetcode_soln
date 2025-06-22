class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        int n=s.length();
        int rm=0;
        if(n%k)
        rm=k-n%k;

        vector<string> re;

        while(rm)
        {
            s+=fill;
            rm--;
        }

        n=s.length();

        for(int i=0;i<n;i+=k)
        {
            re.push_back(s.substr(i,k));
        }  

        return re;

    }
};