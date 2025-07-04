class Solution {
public:

    int func(string w1,string w2)
    {
        if(w1==w2)
        return w1.size();

        int i;
        for(i=0;i<min(w1.size(),w2.size());i++)
        {
            if(w1[i]==w2[i])
            continue;
            
            break;
        }
        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& word) 
    {
        int n=word.size();

        if(n<=2)
        return vector<int>(n,0);

        vector<int> ls(n,0),rs(n,0);

        for(int i=1;i<n;i++)
        {
            int l=func(word[i],word[i-1]);
            ls[i]=max(l,ls[i-1]);
        }

        for(int i=n-2;i>=0;i--)
        {
            int r=func(word[i],word[i+1]);
            rs[i]=max(r,rs[i+1]);
        }

        vector<int> re(n);

        re[0]=rs[1];
        re[n-1]=ls[n-2];

        for(int i=1;i<n-1;i++)
        {
            int lc=func(word[i-1],word[i+1]);
            re[i]=max(ls[i-1],max(rs[i+1],lc));
        }

        return re;
    }
};