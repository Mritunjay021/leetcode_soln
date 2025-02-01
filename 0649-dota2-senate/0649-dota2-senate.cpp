class Solution {
public:
    string predictPartyVictory(string s) 
    {
        int n=s.length();
        
        queue<int> r;
        queue<int> d;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')
            r.push(i);
            else
            d.push(i);
        }

        while(!r.empty() && !d.empty())
        {
            if(r.front()<d.front())
            {
                d.pop();
                r.push(r.front()+n);
                r.pop();
            }
            else
            {
                d.push(d.front()+n);
                r.pop();
                d.pop();
            }
        }
        
        if(r.empty())
        return "Dire";
        else
        return "Radiant";
    }
};