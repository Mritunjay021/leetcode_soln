class Solution {
public:
    int minInsertions(string s) 
    {
        string t=s;
        reverse(t.begin(),t.end());
        int i=s.length();
        vector<int> prev(i+1,0),cur(i+1,0);
        for(int a=1;a<=i;a++)
        {
            for(int b=1;b<=i;b++)
            {
                if(s[a-1]==t[b-1])
                cur[b]=1+prev[b-1];
                else
                cur[b]=max(cur[b-1],prev[b]);
            }
            prev=cur;
        }
        return i-prev[i];  
    }
};