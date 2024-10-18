class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        
        // dp array to store the minimum ASCII sum of deletions
        vector<int> dp(n + 1, 0);
        
        // Initialize the dp array for s2 being empty (i.e., deleting all characters from s2)
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] + s2[j - 1];
        }
        
        // Iterate over s1 and fill the dp array iteratively
        for (int i = 1; i <= m; i++) {
            int prev = dp[0];  // store the value for dp[i-1][j-1]
            dp[0] += s1[i - 1];  // when s2 is empty, delete all characters from s1
            
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];  // temporarily store the current dp[j] value
                
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev;  // characters match, no deletion needed
                } else {
                    dp[j] = min(dp[j - 1] + s2[j - 1], dp[j] + s1[i - 1]);  // take the min cost of deleting from either string
                }
                
                prev = temp;  // move to the next state
            }
        }
        
        return dp[n];  // the result is the minimum delete sum for the entire strings
    }
};



// class Solution {
// public:

//     int func(string s1, string s2,vector<vector<int>>& dp,int i,int j,int m,int n)
//     {
//         if(i>=m && j>=n)
//         return 0;

//         if(dp[i][j]!=-1)
//         return dp[i][j];
        
//         if(i>=m)
//         return dp[i][j]=s2[j]+func(s1,s2,dp,i,j+1,m,n);

//         else if(j>=n)
//         return dp[i][j]=s1[i]+func(s1,s2,dp,i+1,j,m,n);

//         if(s1[i]==s2[j])
//         dp[i][j]=func(s1,s2,dp,i+1,j+1,m,n);
//         else
//         {
//             int p=s1[i]+func(s1,s2,dp,i+1,j,m,n);
//             int np=s2[j]+func(s1,s2,dp,i,j+1,m,n);
//             dp[i][j]=min(p,np);
//         }

//         return dp[i][j];
//     }

//     int minimumDeleteSum(string s1, string s2) 
//     {
//         int m=s1.length(),n=s2.length();

//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

//         return func(s1,s2,dp,0,0,m,n);
//     }
// };










//     int func(string s1,string s2,vector<vector<int>>& dp,int i,int j)
//     {
//         if(i<0 || j<0)
//         return 0;

//         if(dp[i][j]!=-1)
//         return dp[i][j];

//         if(s1[i] == s2[j])
//         return dp[i][j]=1+func(s1,s2,dp,i-1,j-1);

//         else
//         return dp[i][j]=max(func(s1,s2,dp,i-1,j),func(s1,s2,dp,i,j-1));
//     }


//     void findAllLCS(string& s1, string& s2, vector<vector<int>>& dp, int i, int j, string currLCS, set<string>& allLCS) {
//         if (i < 0 || j < 0) {
//             reverse(currLCS.begin(), currLCS.end());
//             allLCS.insert(currLCS);
//             return;
//         }

//         // If the characters match, include them in the current LCS
//         if (s1[i] == s2[j]) {
//             findAllLCS(s1, s2, dp, i - 1, j - 1, currLCS + s1[i], allLCS);
//         } else {
//             // If they don't match, explore both possible directions
//             if (i > 0 && dp[i - 1][j] == dp[i][j]) 
//                 findAllLCS(s1, s2, dp, i - 1, j, currLCS, allLCS);
//             if (j > 0 && dp[i][j - 1] == dp[i][j]) 
//                 findAllLCS(s1, s2, dp, i, j - 1, currLCS, allLCS);
//         }
//     }

//     int minimumDeleteSum(string s1, string s2) 
//     {
//         int l1=s1.length(),l2=s2.length();
        
//         vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        
//         func(s1,s2,dp,l1-1,l2-1);
        
//         set<string> allLCS;

//         findAllLCS(s1,s2,dp,l1-1,l2-1,"",allLCS);

//         int re=INT_MAX;

//         for(auto it:allLCS)
//         {
//             int k=0,ans=0;
//             for(int j=0;j<s1.size();j++)
//             {
//                 if(k<it.length() && s1[j]==it[k])
//                 k++;
//                 else
//                 ans+=int(s1[j]);
//             }
//             k=0;
//             for(int j=0;j<s2.size();j++)
//             {
//                 if(k<it.length() &&  s2[j]==it[k])
//                 k++;
//                 else
//                 ans+=int(s2[j]);
//             }
//             re=min(ans,re);
//         }        
//         return re;
//     }
// };

