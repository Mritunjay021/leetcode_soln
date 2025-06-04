class Solution {
public:
    string answerString(string word, int n) 
    {
        if(n == 1)
            return word;
        
        char mx = word[0];
        for(int i = 1; i < word.length(); i++)
        {
            if(word[i] > mx)
                mx = word[i];
        }

        string re = "";
        
        for(int i = 0; i < word.length(); i++)
        {
            if(word[i] == mx)
            {
                int mx = word.length() - n + 1;
                int avl = word.length() - i;
                int len = min(mx, avl);
                
                string nw = word.substr(i, len);
                
                if(nw > re)
                    re = nw;
            }
        }
        
        return re;
    }
};