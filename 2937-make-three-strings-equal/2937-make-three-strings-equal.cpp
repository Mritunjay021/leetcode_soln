class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) 
    {
        if(s1[0]==s2[0] && s2[0]==s3[0])
        {
            int mx=max(s1.length(),max(s2.length(),s3.length()));
            int re=1;
            for(int i=1;i<mx;i++)
            {
                if(s1[i]==s2[i] && s2[i]==s3[i])
                re++;
                else
                break;
            }
            return s3.length()+s2.length()+s1.length()-(3*re); 
        }   
        return -1; 
    }
};