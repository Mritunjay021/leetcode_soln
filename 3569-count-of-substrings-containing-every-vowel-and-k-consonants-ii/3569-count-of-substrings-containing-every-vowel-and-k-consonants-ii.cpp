class Solution {
public:

    long long func(string word,int k)
    {
        unordered_map<char,int> mp;
        long long res=0;
        int ct=0,j=0;

        for(int i=0;i<word.length();i++)
        {
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
            mp[word[i]]++;
            else
            ct++;

            while(mp.size()==5 && ct>=k)
            {
                res+=word.size()-i;
                if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
                {
                    mp[word[j]]--;
                    if(mp[word[j]]==0)
                    mp.erase(word[j]);
                }
                else
                ct--;

                j++;
            }
        }

        return res;
    }

    long long countOfSubstrings(string word, int k) 
    {
        return func(word,k)-func(word,k+1);
    }
};