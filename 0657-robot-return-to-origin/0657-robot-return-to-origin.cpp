class Solution {
public:
    bool judgeCircle(string m) 
    {
        int v=0,h=0;
        for(int i=0;i<m.length();i++)   
        {
            if(m[i]=='U')
            v++;
            else if(m[i]=='D')
            v--;
            else if(m[i]=='L')
            h++;
            else
            h--;
        } 
        if(v==0 && h==0)
        return 1;
        else
        return 0;
    }
};