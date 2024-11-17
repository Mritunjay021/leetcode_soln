// // class Solution {
// // public:

// //     void sorting(string &s1,string& s2,string& s3)
// //     {
// //         if(s1>s2)
// //         swap(s1,s2);

// //         if(s2>s3)
// //         swap(s2,s3);

// //         if(s1>s2)
// //         swap(s1,s2);
// //     }

// //     string subs(string& s,string& t)
// //     {
// //         int n=s.length();
// //         int m=t.length();
// //         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
// //         for(int i=1;i<=n;i++)
// //         {
// //             for(int j=1;j<=m;j++)
// //             {
// //                 if(s[i-1]==t[j-1])
// //                 dp[i][j]=1+dp[i-1][j-1];
// //                 else
// //                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
// //             }
// //         }
// //         string st="";
// //         int i=n,j=m;
// //         while(i>0 && j>0)
// //         {
// //             if(s[i-1]==t[j-1])
// //             {
// //                 st=s[i-1]+st;
// //                 i--;j--;
// //             }
// //             else if(dp[i-1][j]>dp[i][j-1])
// //             {
// //                 st=s[i-1]+st;
// //                 i--;
// //             }
// //             else
// //             {
// //                 st=t[j-1]+st;
// //                 j--;
// //             }
// //         } 
// //         while(i>0)
// //         {
// //             st=s[i-1]+st;
// //             i--;
// //         }
// //         while(j>0)
// //         {
// //             st=t[j-1]+st;
// //             j--;
// //         }
// //         return st;
// //     }

// //     string minimumString(string s, string t, string u) 
// //     {
// //         sorting(s,t,u);
        
// //         string st=subs(s,t);

// //         st=subs(st,u);

// //         return st;   
// //     }
// // };




// class Solution {
// public:
    
//     string merge(string s, string t) 
//     {
//         int n = s.length();
//         int m = t.length();
//         if (s.find(t) != string::npos) return s;
        
//         if (t.find(s) != string::npos) return t;    
        
//         for (int i = 0; i < n; ++i) {
//             if (t.substr(0, n - i) == s.substr(i)) {
//                 return s + t.substr(n - i);
//             }
//         }
//         return s + t;  
//     }

//     string minimumString(string a, string b, string c) 
//     {
//         vector<string> candidates = {
//             merge(merge(a, b), c),  // a -> b -> c
//             merge(merge(a, c), b),  // a -> c -> b
//             merge(merge(b, a), c),  // b -> a -> c
//             merge(merge(b, c), a),  // b -> c -> a
//             merge(merge(c, a), b),  // c -> a -> b
//             merge(merge(c, b), a)   // c -> b -> a
//         };

//         // Find the shortest and lexicographically smallest result
//         string result = candidates[0];
//         for (const string& candidate : candidates) {
//             if (candidate.length() <= result.length() && candidate < result) 
//             {
//                 result = candidate;
//             }
//         }

//         return result;
//     }
// };



class Solution {
public:
    // Function to merge two strings considering the largest suffix-prefix overlap
    string merge(string s, string t) {
        // If t is a substring of s, no need to merge
        if (s.find(t) != string::npos) return s;
        // If s is a substring of t, return t
        if (t.find(s) != string::npos) return t;
        
        int n = s.length();
        int m = t.length();
        
        // Find the largest suffix of s that matches the prefix of t
        for (int i = 0; i < n; ++i) {
            if (t.substr(0, n - i) == s.substr(i)) {
                return s + t.substr(n - i);
            }
        }
        return s + t;  // If no overlap, concatenate the two strings
    }

    string minimumString(string a, string b, string c) {
        // Try all permutations of merging the strings
        vector<string> candidates = {
            merge(merge(a, b), c),  // a -> b -> c
            merge(merge(a, c), b),  // a -> c -> b
            merge(merge(b, a), c),  // b -> a -> c
            merge(merge(b, c), a),  // b -> c -> a
            merge(merge(c, a), b),  // c -> a -> b
            merge(merge(c, b), a)   // c -> b -> a
        };

        // Find the shortest and lexicographically smallest result
        string result = candidates[0];
        for (const string& candidate : candidates) {
            if (candidate.length() < result.length() || 
                (candidate.length() == result.length() && candidate < result)) {
                result = candidate;
            }
        }

        return result;
    }
};
