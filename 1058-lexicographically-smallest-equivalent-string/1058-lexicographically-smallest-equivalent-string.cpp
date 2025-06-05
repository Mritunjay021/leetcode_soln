class Solution {
public:

    int find(vector<int>& par,int x)
    {
        if(par[x]!=x)
        {
            par[x]=find(par,par[x]);
        }
        return par[x];
    }

    void unionchar(vector<int>& par,int x,int y)
    {
        int rx=find(par,x);
        int ry=find(par,y);

        if(rx!=ry)
        {
            if(rx<ry)
            par[ry]=rx;
            else
            par[rx]=ry;
        }
    }

    string smallestEquivalentString(string s1, string s2, string base) 
    {
        vector<int> par(26);
        string re="";

        for(int i=0;i<26;i++)
        {
            par[i]=i;
        }    

        for(int i=0;i<s1.length();i++)
        {
            int c1=s1[i]-'a';
            int c2=s2[i]-'a';
            unionchar(par,c1,c2);
        }

        for(int i=0;i<base.length();i++)
        {
            int ch=base[i]-'a';
            int rf=find(par,ch);
            re+=(char)('a'+rf);
        }
        return re;
    }
};