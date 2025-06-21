class Solution {
public:
    int minimumDeletions(string word, int k) 
    {
        vector<int> hash(26,0);
        
        for(char c:word)
        {
            hash[c-'a']++;
        }

        sort(hash.begin(),hash.end());

        int mn=INT_MAX;

        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0)
            {
                int c=0;
                for(int j=0;j<26;j++)
                {
                    if(hash[j]==0)
                    continue;
                    if(hash[j]<hash[i])
                    c+=hash[j];
                    if(hash[j]>(hash[i]+k))
                    c+=hash[j]-hash[i]-k;
                    
                }
                mn=min(mn,c);
            }
        }
        return mn;
    }
};