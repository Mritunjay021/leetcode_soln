class Solution {
public:

    void odd(int i,int& mx,int n,string s,string& str)
    {
        int j = i - 1, k = i + 1, l = 1;
        while (j >= 0 && k < n && s[j] == s[k]) {
            j--;
            k++;
            l += 2;
        }
        if (l > mx) {
            mx = l;
            str = s.substr(j + 1, l);
        }
    }

    void even(int i,int& mx,int n,string s,string& str)
    {
        int j=i,k = i+1,l = 0;
        while (j >= 0 && k < n && s[j] == s[k]) 
        {
            j--;
            k++;
            l += 2;
        }
        if (l > mx) 
        {
            mx = l;
            str = s.substr(j + 1, l);
        }
    }
    

    string longestPalindrome(string s) {
        int n = s.length();
        int mx = 0;
        string str = "";

        for (int i = 0; i < n; i++) 
        {
            odd(i,mx,n,s,str);

            even(i,mx,n,s,str);
        }

        return str;
    }
};
